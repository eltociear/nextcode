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

#ifndef LLVM_ALLOC_HELPERS_H
#define LLVM_ALLOC_HELPERS_H
#include <llvm-c/Types.h>

#include <llvm/ADT/SmallSet.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/Analysis/OptimizationRemarkEmitter.h>
#include <llvm/IR/Instructions.h>

#include <utility>
#include <map>

#include "llvm-pass-helpers.h"

namespace language_alloc {

    struct CheckInst {
        struct Frame {
            llvm::Instruction *parent;
            uint32_t offset;
            llvm::Instruction::use_iterator use_it;
            llvm::Instruction::use_iterator use_end;
        };
        typedef llvm::SmallVector<Frame,4> Stack;
    };

    struct MemOp {
        llvm::Instruction *inst;
        uint64_t offset = 0;
        unsigned opno;
        uint32_t size = 0;
        bool isobjref:1;
        bool isaggr:1;
        MemOp(llvm::Instruction *inst, unsigned opno)
            : inst(inst),
              opno(opno),
              isobjref(false),
              isaggr(false)
        {}
    };
    struct Field {
        uint32_t size;
        bool hasobjref:1;
        bool hasaggr:1;
        bool multiloc:1;
        bool hasload:1;
        llvm::Type *elty;
        llvm::SmallVector<MemOp,4> accesses;
        Field(uint32_t size, llvm::Type *elty)
            : size(size),
              hasobjref(false),
              hasaggr(false),
              multiloc(false),
              hasload(false),
              elty(elty)
        {
        }
    };

    struct AllocUseInfo {
        llvm::SmallSet<llvm::Instruction*,16> uses;
        llvm::SmallSet<llvm::CallInst*,4> preserves;
        std::map<uint32_t,Field> memops;
        // Completely unknown use
        bool escaped:1;
        // Address is leaked to functions that doesn't care where the object is allocated.
        bool addrescaped:1;
        // There are reader of the memory
        bool hasload:1;
        // There are uses in gc_preserve intrinsics or ccall roots
        bool haspreserve:1;
        // There are objects fields being loaded
        bool refload:1;
        // There are objects fields being stored
        bool refstore:1;
        // There are typeof call
        // This can be optimized without optimizing out the allocation itself
        bool hastypeof:1;
        // There are store/load/memset on this object with offset or size (or value for memset)
        // that cannot be statically computed.
        // This is a weaker form of `addrescaped` since `hasload` can still be used
        // to see if the memory is actually being used
        bool hasunknownmem:1;
        // The object is returned
        bool returned:1;
        // The object is used in an error function
        bool haserror:1;
        // For checking attributes of "uninitialized" or "zeroed" or unknown
        llvm::AllocFnKind allockind;

        // The alloc has a Julia object reference not in an explicit field.
        bool has_unknown_objref:1;
        // The alloc has an aggregate Julia object reference not in an explicit field.
        bool has_unknown_objrefaggr:1;

        void reset()
        {
            escaped = false;
            addrescaped = false;
            hasload = false;
            haspreserve = false;
            refload = false;
            refstore = false;
            hastypeof = false;
            hasunknownmem = false;
            returned = false;
            haserror = false;
            allockind = llvm::AllocFnKind::Unknown;
            has_unknown_objref = false;
            has_unknown_objrefaggr = false;
            uses.clear();
            preserves.clear();
            memops.clear();
        }
        void dump(llvm::raw_ostream &OS);
        void dump();
        bool addMemOp(llvm::Instruction *inst, unsigned opno, uint32_t offset, llvm::Type *elty,
                      bool isstore, const llvm::DataLayout &DL);
        std::pair<const uint32_t,Field> &getField(uint32_t offset, uint32_t size, llvm::Type *elty);
        std::map<uint32_t,Field>::iterator findLowerField(uint32_t offset)
        {
            // Find the last field that starts no higher than `offset`.
            auto it = memops.upper_bound(offset);
            if (it != memops.begin())
                return --it;
            return memops.end();
        }
    };

    struct EscapeAnalysisRequiredArgs {
        AllocUseInfo &use_info; // The returned escape analysis data
        CheckInst::Stack &check_stack; // A preallocated stack to be used for escape analysis
        JuliaPassContext &pass; // The current optimization pass (for accessing intrinsic functions)
        const llvm::DataLayout &DL; // The module's data layout (for handling GEPs/memory operations)
    };

    struct EscapeAnalysisOptionalArgs {
        //A set of basic blocks to run escape analysis over. Uses outside these basic blocks
        //will not be considered. Defaults to nullptr, which means all uses of the allocation
        //are considered
        const llvm::SmallPtrSetImpl<const llvm::BasicBlock*> *valid_set;
        llvm::OptimizationRemarkEmitter *ORE = nullptr;

        EscapeAnalysisOptionalArgs() = default;

        EscapeAnalysisOptionalArgs &with_valid_set(decltype(valid_set) valid_set) {
            this->valid_set = valid_set;
            return *this;
        }

        EscapeAnalysisOptionalArgs &with_optimization_remark_emitter(decltype(ORE) ORE) {
            this->ORE = ORE;
            return *this;
        }
    };

    void runEscapeAnalysis(llvm::CallInst *I, EscapeAnalysisRequiredArgs required, EscapeAnalysisOptionalArgs options=EscapeAnalysisOptionalArgs());
}


#endif
