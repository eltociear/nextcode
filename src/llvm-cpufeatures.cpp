/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 */

// Lower intrinsics that expose subtarget information to the language. This makes it
// possible to write code that changes behavior based on, e.g., the availability of
// specific CPU features.
//
// The following intrinsics are supported:
// - julia.cpu.have_fma.$typ: returns 1 if the platform supports hardware-accelerated FMA.
//
// Some of these intrinsics are overloaded, i.e., they are suffixed with a type name.
// To extend support, make sure codegen (in intrinsics.cpp) knows how to emit them.
//
// XXX: can / do we want to make this a codegen pass to enable querying TargetPassConfig
//      instead of using the global target machine?

#include "llvm-version.h"
#include "passes.h"

#include <llvm/ADT/Statistic.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Support/Debug.h>

#include "jitlayers.h"

#define DEBUG_TYPE "cpufeatures"

using namespace llvm;

STATISTIC(LoweredWithFMA, "Number of have_fma's that were lowered to true");
STATISTIC(LoweredWithoutFMA, "Number of have_fma's that were lowered to false");

extern JuliaOJIT *language_ExecutionEngine;

// whether this platform unconditionally (i.e. without needing multiversioning) supports FMA
Optional<bool> always_have_fma(Function &intr, const Triple &TT) LANGUAGE_NOTSAFEPOINT {
    if (TT.isAArch64()) {
        auto intr_name = intr.getName();
        auto typ = intr_name.substr(strlen("julia.cpu.have_fma."));
        return typ == "f32" || typ == "f64";
    } else {
        return None;
    }
}

static bool have_fma(Function &intr, Function &caller, const Triple &TT) LANGUAGE_NOTSAFEPOINT {
    auto unconditional = always_have_fma(intr, TT);
    if (unconditional)
        return *unconditional;

    auto intr_name = intr.getName();
    auto typ = intr_name.substr(strlen("julia.cpu.have_fma."));

    Attribute FSAttr = caller.getFnAttribute("target-features");
    StringRef FS =
        FSAttr.isValid() ? FSAttr.getValueAsString() : language_ExecutionEngine->getTargetFeatureString();

    SmallVector<StringRef, 128> Features;
    FS.split(Features, ',');
    for (StringRef Feature : Features)
    if (TT.isARM()) {
      if (Feature == "+vfp4")
        return typ == "f32" || typ == "f64";
      else if (Feature == "+vfp4sp")
        return typ == "f32";
    } else if (TT.isX86()) {
      if (Feature == "+fma" || Feature == "+fma4")
        return typ == "f32" || typ == "f64";
    }

    return false;
}

void lowerHaveFMA(Function &intr, Function &caller, const Triple &TT, CallInst *I) LANGUAGE_NOTSAFEPOINT {
    if (have_fma(intr, caller, TT)) {
        ++LoweredWithFMA;
        I->replaceAllUsesWith(ConstantInt::get(I->getType(), 1));
    } else {
        ++LoweredWithoutFMA;
        I->replaceAllUsesWith(ConstantInt::get(I->getType(), 0));
    }
    return;
}

bool lowerCPUFeatures(Module &M) LANGUAGE_NOTSAFEPOINT
{
    auto TT = Triple(M.getTargetTriple());
    SmallVector<Instruction*,6> Materialized;

    for (auto &F: M.functions()) {
        auto FN = F.getName();

        if (FN.startswith("julia.cpu.have_fma.")) {
            for (Use &U: F.uses()) {
                User *RU = U.getUser();
                CallInst *I = cast<CallInst>(RU);
                lowerHaveFMA(F, *I->getParent()->getParent(), TT, I);
                Materialized.push_back(I);
            }
        }
    }

    if (!Materialized.empty()) {
        for (auto I: Materialized) {
            I->eraseFromParent();
        }
#ifdef LANGUAGE_VERIFY_PASSES
        assert(!verifyLLVMIR(M));
#endif
        return true;
    } else {
        return false;
    }
}

PreservedAnalyses CPUFeaturesPass::run(Module &M, ModuleAnalysisManager &AM)
{
    if (lowerCPUFeatures(M)) {
        return PreservedAnalyses::allInSet<CFGAnalyses>();
    }
    return PreservedAnalyses::all();
}
