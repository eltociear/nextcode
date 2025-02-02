/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with NeXTech, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 19, 2024
// Technology: C/C++20 - ISO/IEC 14882:2020(E) 
// Purpose: The ccall, cglobal, and llvm intrinsics 

// Mark our stats as being from ccall
#undef DEBUG_TYPE
#define DEBUG_TYPE "code_irgen_ccall"

STATISTIC(RuntimeSymLookups, "Number of runtime symbol lookups emitted");
STATISTIC(PLTThunks, "Number of PLT Thunks emitted");
STATISTIC(PLT, "Number of direct PLT entries emitted");
STATISTIC(EmittedCGlobals, "Number of C globals emitted");
STATISTIC(EmittedLLVMCalls, "Number of llvmcall intrinsics emitted");

#define _CCALL_STAT(name) code_transformed_ccall__##name
#define CCALL_STAT(name) _CCALL_STAT(name)
#define TRANSFORMED_CCALL_STAT(name) STATISTIC(_CCALL_STAT(name), "Number of " #name " ccalls intercepted")
TRANSFORMED_CCALL_STAT(code_array_ptr);
TRANSFORMED_CCALL_STAT(code_value_ptr);
TRANSFORMED_CCALL_STAT(code_cpu_pause);
TRANSFORMED_CCALL_STAT(code_cpu_wake);
TRANSFORMED_CCALL_STAT(code_gc_safepoint);
TRANSFORMED_CCALL_STAT(code_get_ptls_states);
TRANSFORMED_CCALL_STAT(code_threadid);
TRANSFORMED_CCALL_STAT(code_get_tls_world_age);
TRANSFORMED_CCALL_STAT(code_gc_enable_disable_finalizers_internal);
TRANSFORMED_CCALL_STAT(code_get_current_task);
TRANSFORMED_CCALL_STAT(code_set_next_task);
TRANSFORMED_CCALL_STAT(code_sigatomic_begin);
TRANSFORMED_CCALL_STAT(code_sigatomic_end);
TRANSFORMED_CCALL_STAT(code_string_ptr);
TRANSFORMED_CCALL_STAT(code_symbol_name);
TRANSFORMED_CCALL_STAT(code_genericmemory_owner);
TRANSFORMED_CCALL_STAT(code_alloc_genericmemory);
TRANSFORMED_CCALL_STAT(memcpy);
TRANSFORMED_CCALL_STAT(memset);
TRANSFORMED_CCALL_STAT(memmove);
TRANSFORMED_CCALL_STAT(code_object_id);
#undef TRANSFORMED_CCALL_STAT
extern "C" JL_DLLEXPORT code_value_t *icode_genericmemory_owner(code_genericmemory_t *m JL_PROPAGATES_ROOT) JL_NOTSAFEPOINT;

STATISTIC(EmittedCCalls, "Number of ccalls emitted");
STATISTIC(DeferredCCallLookups, "Number of ccalls looked up at runtime");
STATISTIC(LiteralCCalls, "Number of ccalls directly emitted through a pointer");
STATISTIC(RetBoxedCCalls, "Number of ccalls that were retboxed");
STATISTIC(SRetCCalls, "Number of ccalls that were marked sret");

// somewhat unusual variable, in that aotcompile wants to get the address of this for a sanity check
GlobalVariable *code_emit_RTLD_DEFAULT_var(Module *M)
{
    return prepare_global_in(M, codeRTLD_DEFAULT_var);
}


// Find or create the GVs for the library and symbol lookup.
// Return `runtime_lib` (whether the library name is a string)
// The `lib` and `sym` GV returned may not be in the current module.
static bool runtime_sym_gvs(code_codectx_t &ctx, const char *f_lib, const char *f_name,
                            GlobalVariable *&lib, GlobalVariable *&sym)
{
    auto M = &ctx.emission_context.shared_module();
    bool runtime_lib = false;
    GlobalVariable *libptrgv;
    code_codegen_params_t::SymMapGV *symMap;
    if ((intptr_t)f_lib == (intptr_t)JL_EXE_LIBNAME) {
        libptrgv = prepare_global_in(M, codeexe_var);
        symMap = &ctx.emission_context.symMapExe;
    }
    else if ((intptr_t)f_lib == (intptr_t)JL_LIBCODE_INTERNAL_DL_LIBNAME) {
        libptrgv = prepare_global_in(M, codedlli_var);
        symMap = &ctx.emission_context.symMapDlli;
    }
    else if ((intptr_t)f_lib == (intptr_t)JL_LIBCODE_DL_LIBNAME) {
        libptrgv = prepare_global_in(M, codedll_var);
        symMap = &ctx.emission_context.symMapDll;
    }
    else if (f_lib == NULL) {
        libptrgv = code_emit_RTLD_DEFAULT_var(M);
        symMap = &ctx.emission_context.symMapDefault;
    }
    else {
        std::string name = "ccalllib_";
        name += llvm::sys::path::filename(f_lib);
        name += std::to_string(code_atomic_fetch_add_relaxed(&globalUniqueGeneratedNames, 1));
        runtime_lib = true;
        auto &libgv = ctx.emission_context.libMapGV[f_lib];
        if (libgv.first == NULL) {
            libptrgv = new GlobalVariable(*M, getPointerTy(M->getContext()), false,
                                          GlobalVariable::ExternalLinkage,
                                          Constant::getNullValue(getPointerTy(M->getContext())), name);
            libgv.first = libptrgv;
        }
        else {
            libptrgv = libgv.first;
        }
        symMap = &libgv.second;
    }

    GlobalVariable *&llvmgv = (*symMap)[f_name];
    if (llvmgv == NULL) {
        std::string name = "ccall_";
        name += f_name;
        name += "_";
        name += std::to_string(code_atomic_fetch_add_relaxed(&globalUniqueGeneratedNames, 1));
        auto T_pvoidfunc = CodeType::get_pvoidfunc_ty(M->getContext());
        llvmgv = new GlobalVariable(*M, T_pvoidfunc, false,
                                    GlobalVariable::ExternalLinkage,
                                    Constant::getNullValue(T_pvoidfunc), name);
    }

    lib = libptrgv;
    sym = llvmgv;
    return runtime_lib;
}

static Value *runtime_sym_lookup(
        code_codegen_params_t &emission_context,
        IRBuilder<> &irbuilder,
        code_codectx_t *ctx,
        PointerType *funcptype, const char *f_lib, code_value_t *lib_expr,
        const char *f_name, Function *f,
        GlobalVariable *libptrgv,
        GlobalVariable *llvmgv, bool runtime_lib)
{
    ++RuntimeSymLookups;
    // in pseudo-code, this function emits the following:
    //   global HMODULE *libptrgv
    //   global void **llvmgv
    //   if (*llvmgv == NULL) {
    //       *llvmgv = code_load_and_lookup(f_lib, f_name, libptrgv);
    //   }
    //   return (*llvmgv)
    auto T_pvoidfunc = CodeType::get_pvoidfunc_ty(irbuilder.getContext());
    BasicBlock *enter_bb = irbuilder.GetInsertBlock();
    BasicBlock *dlsym_lookup = BasicBlock::Create(irbuilder.getContext(), "dlsym");
    BasicBlock *ccall_bb = BasicBlock::Create(irbuilder.getContext(), "ccall");
    Constant *initnul = ConstantPointerNull::get(T_pvoidfunc);
    LoadInst *llvmf_orig = irbuilder.CreateAlignedLoad(T_pvoidfunc, llvmgv, Align(sizeof(void*)));
    setName(emission_context, llvmf_orig, f_name + StringRef(".cached"));
    // This in principle needs a consume ordering so that load from
    // this pointer sees a valid value. However, this is not supported by
    // LLVM (or agreed on in the C/C++ standard FWIW) and should be
    // almost impossible to happen on every platform we support since this
    // ordering is enforced by the hardware and LLVM has to speculate an
    // invalid load from the `cglobal` but doesn't depend on the `cglobal`
    // value for this to happen.
    llvmf_orig->setAtomic(AtomicOrdering::Unordered);
    auto nonnull = irbuilder.CreateICmpNE(llvmf_orig, initnul);
    setName(emission_context, nonnull, "is_cached");
    irbuilder.CreateCondBr(
            nonnull,
            ccall_bb,
            dlsym_lookup);

    assert(f->getParent() != NULL);
    dlsym_lookup->insertInto(f);
    irbuilder.SetInsertPoint(dlsym_lookup);
    Instruction *llvmf;
    Value *nameval = stringConstPtr(emission_context, irbuilder, f_name);
    if (lib_expr) {
        code_cgval_t libval = emit_expr(*ctx, lib_expr);
        llvmf = irbuilder.CreateCall(prepare_call_in(code_builderModule(irbuilder), codelazydlsym_func),
                    { boxed(*ctx, libval), nameval });
    }
    else {
        Value *libname;
        if (runtime_lib) {
            libname = stringConstPtr(emission_context, irbuilder, f_lib);
        }
        else {
            // f_lib is actually one of the special sentinel values
            libname = ConstantExpr::getIntToPtr(ConstantInt::get(emission_context.DL.getIntPtrType(irbuilder.getContext()), (uintptr_t)f_lib), getPointerTy(irbuilder.getContext()));
        }
        auto lookup = irbuilder.CreateCall(prepare_call_in(code_builderModule(irbuilder), codedlsym_func),
                    { libname, nameval, libptrgv });
        llvmf = lookup;
    }
    setName(emission_context, llvmf, f_name + StringRef(".found"));
    StoreInst *store = irbuilder.CreateAlignedStore(llvmf, llvmgv, Align(sizeof(void*)));
    store->setAtomic(AtomicOrdering::Release);
    irbuilder.CreateBr(ccall_bb);

    ccall_bb->insertInto(f);
    irbuilder.SetInsertPoint(ccall_bb);
    PHINode *p = irbuilder.CreatePHI(T_pvoidfunc, 2);
    p->addIncoming(llvmf_orig, enter_bb);
    p->addIncoming(llvmf, llvmf->getParent());
    setName(emission_context, p, f_name);
    return p;
}

static Value *runtime_sym_lookup(
        code_codectx_t &ctx,
        PointerType *funcptype, const char *f_lib, code_value_t *lib_expr,
        const char *f_name, Function *f)
{
    auto T_pvoidfunc = CodeType::get_pvoidfunc_ty(ctx.builder.getContext());
    GlobalVariable *libptrgv;
    GlobalVariable *llvmgv;
    bool runtime_lib;
    if (lib_expr) {
        // for computed library names, generate a global variable to cache the function
        // pointer just for this call site.
        runtime_lib = true;
        libptrgv = NULL;
        std::string gvname = "libname_";
        gvname += f_name;
        gvname += "_";
        gvname += std::to_string(code_atomic_fetch_add_relaxed(&globalUniqueGeneratedNames, 1));
        llvmgv = new GlobalVariable(*code_Module, T_pvoidfunc, false,
                                    GlobalVariable::ExternalLinkage,
                                    Constant::getNullValue(T_pvoidfunc), gvname);
    }
    else {
        runtime_lib = runtime_sym_gvs(ctx, f_lib, f_name, libptrgv, llvmgv);
        libptrgv = prepare_global_in(code_Module, libptrgv);
    }
    llvmgv = prepare_global_in(code_Module, llvmgv);
    return runtime_sym_lookup(ctx.emission_context, ctx.builder, &ctx, funcptype, f_lib, lib_expr, f_name, f, libptrgv, llvmgv, runtime_lib);
}

// Emit a "PLT" entry that will be lazily initialized
// when being called the first time.
static GlobalVariable *emit_plt_thunk(
        code_codectx_t &ctx,
        FunctionType *functype, const AttributeList &attrs,
        CallingConv::ID cc, const char *f_lib, const char *f_name,
        GlobalVariable *libptrgv, GlobalVariable *llvmgv,
        bool runtime_lib)
{
    ++PLTThunks;
    auto M = &ctx.emission_context.shared_module();
    PointerType *funcptype = PointerType::get(functype, 0);
    libptrgv = prepare_global_in(M, libptrgv);
    llvmgv = prepare_global_in(M, llvmgv);
    std::string fname;
    raw_string_ostream(fname) << "codeplt_" << f_name << "_" << code_atomic_fetch_add_relaxed(&globalUniqueGeneratedNames, 1);
    Function *plt = Function::Create(functype,
                                     GlobalVariable::PrivateLinkage,
                                     fname, M);
    plt->setAttributes(attrs);
    if (cc != CallingConv::C)
        plt->setCallingConv(cc);
    auto T_pvoidfunc = CodeType::get_pvoidfunc_ty(M->getContext());
    GlobalVariable *got = new GlobalVariable(*M, T_pvoidfunc, false,
                                             GlobalVariable::ExternalLinkage,
                                             plt,
                                             fname + "_got");
    if (runtime_lib) {
        got->addAttribute("code.libname", f_lib);
    } else {
        got->addAttribute("code.libidx", std::to_string((uintptr_t) f_lib));
    }
    got->addAttribute("code.fname", f_name);
    BasicBlock *b0 = BasicBlock::Create(M->getContext(), "top", plt);
    IRBuilder<> irbuilder(b0);
    Value *ptr = runtime_sym_lookup(ctx.emission_context, irbuilder, NULL, funcptype, f_lib, NULL, f_name, plt, libptrgv,
                                    llvmgv, runtime_lib);
    StoreInst *store = irbuilder.CreateAlignedStore(ptr, got, Align(sizeof(void*)));
    store->setAtomic(AtomicOrdering::Release);
    SmallVector<Value*, 16> args;
    for (auto &arg : plt->args())
        args.push_back(&arg);
    #if JL_LLVM_VERSION < 170000
    assert(cast<PointerType>(ptr->getType())->isOpaqueOrPointeeTypeMatches(functype));
    #endif
    CallInst *ret = irbuilder.CreateCall(
        functype,
        ptr, ArrayRef<Value*>(args));
    ret->setAttributes(attrs);
    if (cc != CallingConv::C)
        ret->setCallingConv(cc);
    // NoReturn function can trigger LLVM verifier error when declared as
    // MustTail since other passes might replace the `ret` with
    // `unreachable` (LLVM should probably accept `unreachable`).
    if (hasFnAttr(attrs, Attribute::NoReturn)) {
        irbuilder.CreateUnreachable();
    }
    else {
        // musttail support is very bad on ARM, PPC, PPC64 (as of LLVM 3.9)
        // Known failures includes vararg (not needed here) and sret.
        if (ctx.emission_context.TargetTriple.isX86() || (ctx.emission_context.TargetTriple.isAArch64() && !ctx.emission_context.TargetTriple.isOSDarwin())) {
            // Ref https://bugs.llvm.org/show_bug.cgi?id=47058
            // LLVM, as of 10.0.1 emits wrong/worse code when musttail is set
            // Apple silicon macs give an LLVM ERROR if musttail is set here #44107.
            if (!attrs.hasAttrSomewhere(Attribute::ByVal))
                ret->setTailCallKind(CallInst::TCK_MustTail);
        }
        if (functype->getReturnType() == getVoidTy(irbuilder.getContext())) {
            irbuilder.CreateRetVoid();
        }
        else {
            irbuilder.CreateRet(ret);
        }
    }
    irbuilder.ClearInsertionPoint();

    return got;
}

static Value *emit_plt(
        code_codectx_t &ctx,
        FunctionType *functype,
        const AttributeList &attrs,
        CallingConv::ID cc, const char *f_lib, const char *f_name)
{
    ++PLT;
    // Don't do this for vararg functions so that the `musttail` is only
    // an optimization and is not required to function correctly.
    assert(!functype->isVarArg());
    GlobalVariable *libptrgv;
    GlobalVariable *llvmgv;
    bool runtime_lib = runtime_sym_gvs(ctx, f_lib, f_name, libptrgv, llvmgv);

    auto &pltMap = ctx.emission_context.allPltMap[attrs];
    auto key = std::make_tuple(llvmgv, functype, cc);
    GlobalVariable *&sharedgot = pltMap[key];
    if (!sharedgot) {
        sharedgot = emit_plt_thunk(ctx,
                functype, attrs, cc, f_lib, f_name, libptrgv, llvmgv, runtime_lib);
    }
    GlobalVariable *got = prepare_global_in(code_Module, sharedgot);
    LoadInst *got_val = ctx.builder.CreateAlignedLoad(got->getValueType(), got, Align(sizeof(void*)));
    setName(ctx.emission_context, got_val, f_name);
    // See comment in `runtime_sym_lookup` above. This in principle needs a
    // consume ordering too. This is even less likely to cause issues though
    // since the only thing we do to this loaded pointer is to call it
    // immediately.
    got_val->setAtomic(AtomicOrdering::Unordered);
    return got_val;
}

// --- ABI Implementations ---
// Partially based on the LDC ABI implementations licensed under the BSD 3-clause license

class AbiLayout {
public:
    virtual ~AbiLayout() {}
    virtual bool use_sret(code_datatype_t *ty, LLVMContext &ctx) = 0;
    virtual bool needPassByRef(code_datatype_t *ty, AttrBuilder&, LLVMContext &ctx, Type* llvm_t) = 0;
    virtual Type *preferred_llvm_type(code_datatype_t *ty, bool isret, LLVMContext &ctx) const = 0;
};

// Determine if object of bitstype ty maps to a native x86 SIMD type (__m128, __m256, or __m512) in C
static bool is_native_simd_type(code_datatype_t *dt) {
    size_t size = code_datatype_size(dt);
    if (size != 16 && size != 32 && size != 64)
        // Wrong size for xmm, ymm, or zmm register.
        return false;
    uint32_t n = code_datatype_nfields(dt);
    if (n<2)
        // Not mapped to SIMD register.
        return false;
    code_value_t *ft0 = code_field_type(dt, 0);
    for (uint32_t i = 1; i < n; ++i)
        if (code_field_type(dt, i) != ft0)
            // Not homogeneous
            return false;
    // Type is homogeneous.  Check if it maps to LLVM vector.
    return code_special_vector_alignment(n, ft0) != 0;
}

#include "abi_llvm.cpp"

#include "abi_arm.cpp"
#include "abi_aarch64.cpp"
#include "abi_ppc64le.cpp"
#include "abi_win32.cpp"
#include "abi_win64.cpp"
#include "abi_x86_64.cpp"
#include "abi_x86.cpp"

#if defined ABI_LLVM
  typedef ABI_LLVMLayout DefaultAbiState;
#elif defined _OS_WINDOWS_
#  if defined _CPU_X86_64_
     typedef ABI_Win64Layout DefaultAbiState;
#  elif defined _CPU_X86_
     typedef ABI_Win32Layout DefaultAbiState;
#  else
#    error Windows is currently only supported on x86 and x86_64
#  endif
#elif defined _CPU_X86_64_
  typedef ABI_x86_64Layout DefaultAbiState;
#elif defined _CPU_X86_
  typedef ABI_x86Layout DefaultAbiState;
#elif defined _CPU_ARM_
  typedef ABI_ARMLayout DefaultAbiState;
#elif defined _CPU_AARCH64_
  typedef ABI_AArch64Layout DefaultAbiState;
#elif defined _CPU_PPC64_
  typedef ABI_PPC64leLayout DefaultAbiState;
#else
#  pragma message("ccall is defaulting to llvm ABI, since no platform ABI has been defined for this CPU/OS combination")
  typedef ABI_LLVMLayout DefaultAbiState;
#endif

// basic type widening and cast conversions
static Value *llvm_type_rewrite(
        code_codectx_t &ctx,
        Value *v, Type *target_type,
        bool issigned) /* determines whether an integer value should be zero or sign extended */
{
    Type *from_type = v->getType();
    if (target_type == from_type)
        return v;

    if (from_type == getVoidTy(ctx.builder.getContext()) || isa<UndefValue>(v))
        return UndefValue::get(target_type); // convert undef (unreachable) -> undef (target_type)

    assert(from_type->isPointerTy() == target_type->isPointerTy()); // expect that all ABIs consider all pointers to be equivalent
    if (target_type->isPointerTy())
        return v;

    // simple integer and float widening & conversion cases
    if (from_type->getPrimitiveSizeInBits() > 0 &&
            target_type->getPrimitiveSizeInBits() == from_type->getPrimitiveSizeInBits())
        return emit_bitcast(ctx, v, target_type);

    if (target_type->isFloatingPointTy() && from_type->isFloatingPointTy()) {
        if (target_type->getPrimitiveSizeInBits() > from_type->getPrimitiveSizeInBits())
            return ctx.builder.CreateFPExt(v, target_type);
        else if (target_type->getPrimitiveSizeInBits() < from_type->getPrimitiveSizeInBits())
            return ctx.builder.CreateFPTrunc(v, target_type);
        else
            return v;
    }

    if (target_type->isIntegerTy() && from_type->isIntegerTy()) {
        if (issigned)
            return ctx.builder.CreateSExtOrTrunc(v, target_type);
        else
            return ctx.builder.CreateZExtOrTrunc(v, target_type);
    }

    // one or both of from_type and target_type is a VectorType or AggregateType
    // LLVM doesn't allow us to cast these values directly, so
    // we need to use this alloca copy trick instead
    // On ARM and AArch64, the ABI requires casting through memory to different
    // sizes.
    Value *from;
    Value *to;
    const DataLayout &DL = ctx.builder.GetInsertBlock()->getModule()->getDataLayout();
    Align align = std::max(DL.getPrefTypeAlign(target_type), DL.getPrefTypeAlign(from_type));
    if (DL.getTypeAllocSize(target_type) >= DL.getTypeAllocSize(from_type)) {
        to = emit_static_alloca(ctx, target_type);
        setName(ctx.emission_context, to, "type_rewrite_buffer");
        cast<AllocaInst>(to)->setAlignment(align);
        from = to;
    }
    else {
        from = emit_static_alloca(ctx, from_type);
        setName(ctx.emission_context, from, "type_rewrite_buffer");
        cast<AllocaInst>(from)->setAlignment(align);
        to = from;
    }
    ctx.builder.CreateAlignedStore(v, from, align);
    auto pun = ctx.builder.CreateAlignedLoad(target_type, to, align);
    setName(ctx.emission_context, pun, "type_rewrite");
    return pun;
}

// --- argument passing and scratch space utilities ---

// Returns ctx.types().T_prcodevalue
static Value *runtime_apply_type_env(code_codectx_t &ctx, code_value_t *ty)
{
    // box if concrete type was not statically known
    Value *args[] = {
        literal_pointer_val(ctx, ty),
        literal_pointer_val(ctx, (code_value_t*)ctx.linfo->def.method->sig),
        ctx.builder.CreateInBoundsGEP(
                ctx.types().T_prcodevalue,
                ctx.spvals_ptr,
                ConstantInt::get(ctx.types().T_size, sizeof(code_svec_t) / sizeof(code_value_t*)))
    };
    auto call = ctx.builder.CreateCall(prepare_call(codeapplytype_func), ArrayRef<Value*>(args));
    addRetAttr(call, Attribute::getWithAlignment(ctx.builder.getContext(), Align(16)));
    return call;
}

static const std::string make_errmsg(const char *fname, int n, const char *err)
{
    std::string _msg;
    raw_string_ostream msg(_msg);
    msg << fname;
    if (n > 0) {
        msg << " argument ";
        msg << n;
    } else
        msg << " return";
    msg << err;
    return msg.str();
}

static void typeassert_input(code_codectx_t &ctx, const code_cgval_t &jvinfo, code_value_t *codeto, code_unionall_t *codeto_env, int argn)
{
    if (codeto != (code_value_t*)code_any_type && !code_subtype(jvinfo.typ, codeto)) {
        if (codeto == (code_value_t*)code_voidpointer_type) {
            // allow a bit more flexibility for what can be passed to (void*) due to Ref{T} conversion behavior in input
            if (!code_is_cpointer_type(jvinfo.typ)) {
                // emit a typecheck, if not statically known to be correct
                emit_cpointercheck(ctx, jvinfo, make_errmsg("ccall", argn + 1, ""));
            }
        }
        else {
            // emit a typecheck, if not statically known to be correct
            std::string msg = make_errmsg("ccall", argn + 1, "");
            if (!codeto_env || !code_has_typevar_from_unionall(codeto, codeto_env)) {
                emit_typecheck(ctx, jvinfo, codeto, msg);
            }
            else {
                code_cgval_t codeto_runtime = mark_code_type(ctx, runtime_apply_type_env(ctx, codeto), true, code_any_type);
                Value *vx = boxed(ctx, jvinfo);
                Value *istype = ctx.builder.CreateICmpNE(
                        ctx.builder.CreateCall(prepare_call(codeisa_func), { vx, boxed(ctx, codeto_runtime) }),
                        ConstantInt::get(getInt32Ty(ctx.builder.getContext()), 0));
                setName(ctx.emission_context, istype, "istype");
                BasicBlock *failBB = BasicBlock::Create(ctx.builder.getContext(), "fail", ctx.f);
                BasicBlock *passBB = BasicBlock::Create(ctx.builder.getContext(), "pass", ctx.f);
                ctx.builder.CreateCondBr(istype, passBB, failBB);

                ctx.builder.SetInsertPoint(failBB);
                just_emit_type_error(ctx, mark_code_type(ctx, vx, true, code_any_type), boxed(ctx, codeto_runtime), msg);
                ctx.builder.CreateUnreachable();
                ctx.builder.SetInsertPoint(passBB);
            }
        }
    }
}

// Emit code to convert argument to form expected by C ABI
// to = desired LLVM type
// codeto = Code type of formal argument
// jvinfo = value of actual argument
static Value *code_to_native(
        code_codectx_t &ctx,
        Type *to, bool toboxed, code_value_t *codeto, code_unionall_t *codeto_env,
        const code_cgval_t &jvinfo,
        bool byRef, int argn)
{
    // We're passing Any
    if (toboxed) {
        assert(!byRef); // don't expect any ABI to pass pointers by pointer
        return boxed(ctx, jvinfo);
    }
    assert(code_is_datatype(codeto) && code_struct_try_layout((code_datatype_t*)codeto));

    typeassert_input(ctx, jvinfo, codeto, codeto_env, argn);
    if (!byRef)
        return emit_unbox(ctx, to, jvinfo, codeto);

    // pass the address of an alloca'd thing, not a box
    // since those are immutable.
    Value *slot = emit_static_alloca(ctx, to);
    unsigned align = code_alignment(codeto);
    cast<AllocaInst>(slot)->setAlignment(Align(align));
    setName(ctx.emission_context, slot, "native_convert_buffer");
    if (!jvinfo.ispointer()) {
        code_aliasinfo_t ai = code_aliasinfo_t::fromTBAA(ctx, jvinfo.tbaa);
        ai.decorateInst(ctx.builder.CreateStore(emit_unbox(ctx, to, jvinfo, codeto), slot));
    }
    else {
        code_aliasinfo_t ai = code_aliasinfo_t::fromTBAA(ctx, jvinfo.tbaa);
        emit_memcpy(ctx, slot, ai, jvinfo, code_datatype_size(codeto), align, align);
    }
    return slot;
}

typedef struct {
    Value *code_ptr;  // if the argument is a run-time computed pointer
    void (*fptr)(void);     // if the argument is a constant pointer
    const char *f_name;   // if the symbol name is known
    const char *f_lib;    // if a library name is specified
    code_value_t *lib_expr; // expression to compute library path lazily
    code_value_t *gcroot;
} native_sym_arg_t;

static inline const char *invalid_symbol_err_msg(bool ccall)
{
    return ccall ?
        "ccall: first argument not a pointer or valid constant expression" :
        "cglobal: first argument not a pointer or valid constant expression";
}

// --- parse :sym or (:sym, :lib) argument into address info ---
static void interpret_symbol_arg(code_codectx_t &ctx, native_sym_arg_t &out, code_value_t *arg, bool ccall, bool llvmcall)
{
    Value *&code_ptr = out.code_ptr;
    void (*&fptr)(void) = out.fptr;
    const char *&f_name = out.f_name;
    const char *&f_lib = out.f_lib;

    code_value_t *ptr = static_eval(ctx, arg);
    if (ptr == NULL) {
        if (code_is_expr(arg) && ((code_expr_t*)arg)->head == code_call_sym && code_expr_nargs(arg) == 3 &&
            code_is_globalref(code_exprarg(arg,0)) && code_globalref_mod(code_exprarg(arg,0)) == code_core_module &&
            code_globalref_name(code_exprarg(arg,0)) == code_symbol("tuple")) {
            // attempt to interpret a non-constant 2-tuple expression as (func_name, lib_name()), where
            // `lib_name()` will be executed when first used.
            code_value_t *name_val = static_eval(ctx, code_exprarg(arg,1));
            if (name_val && code_is_symbol(name_val)) {
                f_name = code_symbol_name((code_sym_t*)name_val);
                out.lib_expr = code_exprarg(arg, 2);
                return;
            }
            else if (name_val && code_is_string(name_val)) {
                f_name = code_string_data(name_val);
                out.gcroot = name_val;
                out.lib_expr = code_exprarg(arg, 2);
                return;
            }
        }
        code_cgval_t arg1 = emit_expr(ctx, arg);
        code_value_t *ptr_ty = arg1.typ;
        if (!code_is_cpointer_type(ptr_ty)) {
            const char *errmsg = invalid_symbol_err_msg(ccall);
            emit_cpointercheck(ctx, arg1, errmsg);
        }
        arg1 = update_code_type(ctx, arg1, (code_value_t*)code_voidpointer_type);
        code_ptr = emit_unbox(ctx, ctx.types().T_ptr, arg1, (code_value_t*)code_voidpointer_type);
    }
    else {
        out.gcroot = ptr;
        if (code_is_tuple(ptr) && code_nfields(ptr) == 1) {
            ptr = code_fieldref(ptr, 0);
        }

        if (code_is_symbol(ptr))
            f_name = code_symbol_name((code_sym_t*)ptr);
        else if (code_is_string(ptr))
            f_name = code_string_data(ptr);

        if (f_name != NULL) {
            // just symbol, default to CodeDLHandle
            // will look in process symbol table
            if (!llvmcall) {
                void *symaddr;
                std::string iname("i");
                iname += f_name;
                if (code_dlsym(code_libcode_internal_handle, iname.c_str(), &symaddr, 0)) {
                    f_lib = JL_LIBCODE_INTERNAL_DL_LIBNAME;
                    f_name = code_symbol_name(code_symbol(iname.c_str()));
                }
                else {
                    f_lib = code_dlfind(f_name);
                }
            }
        }
        else if (code_is_cpointer_type(code_typeof(ptr))) {
            fptr = *(void(**)(void))code_data_ptr(ptr);
        }
        else if (code_is_tuple(ptr) && code_nfields(ptr) > 1) {
            code_value_t *t0 = code_fieldref(ptr, 0);
            if (code_is_symbol(t0))
                f_name = code_symbol_name((code_sym_t*)t0);
            else if (code_is_string(t0))
                f_name = code_string_data(t0);

            code_value_t *t1 = code_fieldref(ptr, 1);
            if (code_is_symbol(t1))
                f_lib = code_symbol_name((code_sym_t*)t1);
            else if (code_is_string(t1))
                f_lib = code_string_data(t1);
            else {
                out.lib_expr = t1;
            }
        }
    }
}

// --- code generator for cglobal ---

static code_cgval_t emit_runtime_call(code_codectx_t &ctx, JL_I::intrinsic f, ArrayRef<code_cgval_t> argv, size_t nargs);

static code_cgval_t emit_cglobal(code_codectx_t &ctx, code_value_t **args, size_t nargs)
{
    ++EmittedCGlobals;
    JL_NARGS(cglobal, 1, 2);
    code_value_t *rt = NULL;
    Value *res;
    native_sym_arg_t sym = {};
    JL_GC_PUSH2(&rt, &sym.gcroot);

    if (nargs == 2) {
        rt = static_eval(ctx, args[2]);
        if (rt == NULL) {
            JL_GC_POP();
            code_cgval_t argv[2];
            argv[0] = emit_expr(ctx, args[1]);
            argv[1] = emit_expr(ctx, args[2]);
            return emit_runtime_call(ctx, JL_I::cglobal, argv, nargs);
        }

        JL_TYPECHK(cglobal, type, rt);
        rt = (code_value_t*)code_apply_type1((code_value_t*)code_pointer_type, rt);
    }
    else {
        rt = (code_value_t*)code_voidpointer_type;
    }
    Type *lrt = ctx.types().T_ptr;
    assert(lrt == code_type_to_llvm(ctx, rt));

    interpret_symbol_arg(ctx, sym, args[1], /*ccall=*/false, false);

    if (sym.f_name == NULL && sym.fptr == NULL && sym.code_ptr == NULL && sym.gcroot != NULL) {
        const char *errmsg = invalid_symbol_err_msg(/*ccall=*/false);
        code_cgval_t arg1 = emit_expr(ctx, args[1]);
        emit_type_error(ctx, arg1, literal_pointer_val(ctx, (code_value_t *)code_pointer_type), errmsg);
        JL_GC_POP();
        return code_cgval_t();
    }

    if (sym.code_ptr != NULL) {
        res = sym.code_ptr;
    }
    else if (sym.fptr != NULL) {
        res = ConstantInt::get(lrt, (uint64_t)sym.fptr);
        if (ctx.emission_context.imaging_mode)
            code_printf(JL_STDERR,"WARNING: literal address used in cglobal for %s; code cannot be statically compiled\n", sym.f_name);
    }
    else {
        if (sym.lib_expr) {
            res = runtime_sym_lookup(ctx, getPointerTy(ctx.builder.getContext()), NULL, sym.lib_expr, sym.f_name, ctx.f);
        }
        else /*if (ctx.emission_context.imaging) */{
            res = runtime_sym_lookup(ctx, getPointerTy(ctx.builder.getContext()), sym.f_lib, NULL, sym.f_name, ctx.f);
        }
    }

    JL_GC_POP();
    return mark_code_type(ctx, res, false, rt);
}

// --- code generator for llvmcall ---

static code_cgval_t emit_llvmcall(code_codectx_t &ctx, code_value_t **args, size_t nargs)
{
    ++EmittedLLVMCalls;
    // parse and validate arguments
    //
    // two forms of llvmcall are supported:
    // - llvmcall(ir, (rettypes...), (argtypes...), args...)
    //   where `ir` represents IR that should be pasted in a function body
    // - llvmcall((mod, fn), (rettypes...), (argtypes...), args...)
    //   where `mod` represents the assembly of an entire LLVM module,
    //   and `fn` the name of the function to call
    JL_NARGSV(llvmcall, 3);
    code_value_t *rt = NULL, *at = NULL, *ir = NULL, *entry = NULL;
    code_value_t *ir_arg = args[1];
    JL_GC_PUSH4(&ir, &rt, &at, &entry);
    if (code_is_ssavalue(ir_arg))
        ir_arg = code_array_ptr_ref((code_array_t*)ctx.source->code, ((code_ssavalue_t*)ir_arg)->id - 1);
    ir = static_eval(ctx, ir_arg);
    if (!ir) {
        emit_error(ctx, "error statically evaluating llvm IR argument");
        JL_GC_POP();
        return code_cgval_t();
    }
    if (code_is_ssavalue(args[2]) && !code_is_long(ctx.source->ssavaluetypes)) {
        code_value_t *rtt = code_array_ptr_ref((code_array_t*)ctx.source->ssavaluetypes, ((code_ssavalue_t*)args[2])->id - 1);
        if (code_is_type_type(rtt))
            rt = code_tparam0(rtt);
    }
    if (!rt) {
        rt = static_eval(ctx, args[2]);
        if (!rt) {
            emit_error(ctx, "error statically evaluating llvmcall return type");
            JL_GC_POP();
            return code_cgval_t();
        }
    }
    if (code_is_ssavalue(args[3]) && !code_is_long(ctx.source->ssavaluetypes)) {
        code_value_t *att = code_array_ptr_ref((code_array_t*)ctx.source->ssavaluetypes, ((code_ssavalue_t*)args[3])->id - 1);
        if (code_is_type_type(att))
            at = code_tparam0(att);
    }
    if (!at) {
        at = static_eval(ctx, args[3]);
        if (!at) {
            emit_error(ctx, "error statically evaluating llvmcall argument tuple");
            JL_GC_POP();
            return code_cgval_t();
        }
    }
    if (code_is_tuple(ir)) {
        // if the IR is a tuple, we expect (mod, fn)
        if (code_nfields(ir) != 2) {
            emit_error(ctx, "Tuple as first argument to llvmcall must have exactly two children");
            JL_GC_POP();
            return code_cgval_t();
        }
        entry = code_fieldref(ir, 1);
        if (!code_is_string(entry)) {
            emit_error(ctx, "Function name passed to llvmcall must be a string");
            JL_GC_POP();
            return code_cgval_t();
        }
        ir = code_fieldref(ir, 0);

        if (!code_is_string(ir) && !code_typetagis(ir, code_array_uint8_type)) {
            emit_error(ctx, "Module IR passed to llvmcall must be a string or an array of bytes");
            JL_GC_POP();
            return code_cgval_t();
        }
    }
    else {
        if (!code_is_string(ir)) {
            emit_error(ctx, "Function IR passed to llvmcall must be a string");
            JL_GC_POP();
            return code_cgval_t();
        }
    }

    JL_TYPECHK(llvmcall, type, rt);
    JL_TYPECHK(llvmcall, type, at);

    // Determine argument types
    //
    // Semantics for arguments are as follows:
    // If the argument type is immutable (including bitstype), we pass the loaded llvm value
    // type. Otherwise we pass a pointer to a code_value_t.
    code_svec_t *tt = ((code_datatype_t *)at)->parameters;
    size_t nargt = code_svec_len(tt);
    SmallVector<llvm::Type*, 0> argtypes;
    SmallVector<Value *, 8> argvals(nargt);
    for (size_t i = 0; i < nargt; ++i) {
        code_value_t *tti = code_svecref(tt,i);
        bool toboxed;
        Type *t = code_type_to_llvm(ctx, tti, &toboxed);
        argtypes.push_back(t);
        if (4 + i > nargs) {
            emit_error(ctx, "Missing arguments to llvmcall!");
            JL_GC_POP();
            return code_cgval_t();
        }
        code_value_t *argi = args[4 + i];
        code_cgval_t arg = emit_expr(ctx, argi);

        Value *v = code_to_native(ctx, t, toboxed, tti, NULL, arg, false, i);
        bool issigned = code_signed_type && code_subtype(tti, (code_value_t*)code_signed_type);
        argvals[i] = llvm_type_rewrite(ctx, v, t, issigned);
    }

    // Determine return type
    code_value_t *rtt = rt;
    bool retboxed;
    Type *rettype = code_type_to_llvm(ctx, rtt, &retboxed);

    // Make sure to find a unique name
    std::string ir_name;
    while (true) {
        raw_string_ostream(ir_name)
            << (ctx.f->getName().str()) << "u"
            << code_atomic_fetch_add_relaxed(&globalUniqueGeneratedNames, 1);
        if (code_Module->getFunction(ir_name) == NULL)
            break;
    }

    // generate a temporary module that contains our IR
    std::unique_ptr<Module> Mod;
    Function *f;
    if (entry == NULL) {
        // we only have function IR, which we should put in a function

        // stringify arguments
        std::string arguments;
        raw_string_ostream argstream(arguments);
        for (SmallVector<Type *, 0>::iterator it = argtypes.begin(); it != argtypes.end(); ++it) {
            if (it != argtypes.begin())
                argstream << ",";
            (*it)->print(argstream);
            argstream << " ";
        }

        // stringify return type
        std::string rstring;
        raw_string_ostream rtypename(rstring);
        rettype->print(rtypename);

        // generate IR function definition
        std::string ir_string;
        raw_string_ostream ir_stream(ir_string);
        ir_stream << "define " << rtypename.str() << " @\"" << ir_name << "\"("
                  << argstream.str() << ") {\n"
                  << code_string_data(ir) << "\n}";

        SMDiagnostic Err = SMDiagnostic();
        Mod = parseAssemblyString(ir_stream.str(), Err, ctx.builder.getContext());

        // backwards compatibility: support for IR with integer pointers
        if (!Mod) {
            std::string compat_arguments;
            raw_string_ostream compat_argstream(compat_arguments);
            for (size_t i = 0; i < nargt; ++i) {
                if (i > 0)
                    compat_argstream << ",";
                code_value_t *tti = code_svecref(tt, i);
                Type *t;
                if (code_is_cpointer_type(tti))
                    t = ctx.types().T_size;
                else
                    t = argtypes[i];
                t->print(compat_argstream);
                compat_argstream << " ";
            }

            std::string compat_rstring;
            raw_string_ostream compat_rtypename(compat_rstring);
            if (code_is_cpointer_type(rtt))
                ctx.types().T_size->print(compat_rtypename);
            else
                rettype->print(compat_rtypename);

            std::string compat_ir_string;
            raw_string_ostream compat_ir_stream(compat_ir_string);
            compat_ir_stream << "define " << compat_rtypename.str() << " @\"" << ir_name
                             << "\"(" << compat_argstream.str() << ") {\n"
                             << code_string_data(ir) << "\n}";

            SMDiagnostic Err = SMDiagnostic();
            Mod =
                parseAssemblyString(compat_ir_stream.str(), Err, ctx.builder.getContext());
        }

        if (!Mod) {
            std::string message = "Failed to parse LLVM assembly: \n";
            raw_string_ostream stream(message);
            Err.print("", stream, true);
            emit_error(ctx, stream.str());
            JL_GC_POP();
            return code_cgval_t();
        }

        f = Mod->getFunction(ir_name);
        f->addFnAttr(Attribute::AlwaysInline);
    }
    else {
        // we have the IR or bitcode of an entire module, which we can parse directly

        if (code_is_string(ir)) {
            SMDiagnostic Err = SMDiagnostic();
            Mod = parseAssemblyString(code_string_data(ir), Err, ctx.builder.getContext());
            if (!Mod) {
                std::string message = "Failed to parse LLVM assembly: \n";
                raw_string_ostream stream(message);
                Err.print("", stream, true);
                emit_error(ctx, stream.str());
                JL_GC_POP();
                return code_cgval_t();
            }
        }
        else {
            auto Buf = MemoryBuffer::getMemBuffer(
                StringRef(code_array_data(ir, char), code_array_nrows(ir)), "llvmcall",
                /*RequiresNullTerminator*/ false);
            Expected<std::unique_ptr<Module>> ModuleOrErr =
                parseBitcodeFile(*Buf, ctx.builder.getContext());
            if (Error Err = ModuleOrErr.takeError()) {
                std::string Message;
                handleAllErrors(std::move(Err),
                                [&](ErrorInfoBase &EIB) { Message = EIB.message(); });
                std::string message = "Failed to parse LLVM bitcode: \n";
                raw_string_ostream stream(message);
                stream << Message;
                emit_error(ctx, stream.str());
                JL_GC_POP();
                return code_cgval_t();
            }
            Mod = std::move(ModuleOrErr.get());
        }

        f = Mod->getFunction(code_string_data(entry));
        if (!f) {
            emit_error(ctx, "Module IR does not contain specified entry function");
            JL_GC_POP();
            return code_cgval_t();
        }
        assert(!f->isDeclaration());
        f->setName(ir_name);
    }

    // backwards compatibility: support for IR with integer pointers
    bool mismatched_pointers = false;
    for (size_t i = 0; i < nargt; ++i) {
        code_value_t *tti = code_svecref(tt, i);
        if (code_is_cpointer_type(tti) &&
            !f->getFunctionType()->getParamType(i)->isPointerTy()) {
            mismatched_pointers = true;
            break;
        }
    }
    if (mismatched_pointers) {
        if (code_options.depwarn) {
            if (code_options.depwarn == JL_OPTIONS_DEPWARN_ERROR)
                code_error("llvmcall with integer pointers is deprecated, "
                         "use an actual pointer type instead.");

            // ensure we only depwarn once per method
            // TODO: lift this into a reusable codegen-level depwarn utility
            static std::set<code_method_t*> llvmcall_depwarns;
            code_method_t *m = ctx.linfo->def.method;
            if (llvmcall_depwarns.find(m) == llvmcall_depwarns.end()) {
                llvmcall_depwarns.insert(m);
                code_printf(JL_STDERR,
                        "WARNING: llvmcall with integer pointers is deprecated.\n"
                        "Use actual pointers instead, replacing i32 or i64 with i8* or ptr\n"
                        "in ");
                code_static_show(JL_STDERR, (code_value_t*) ctx.linfo->def.method);
                code_printf(JL_STDERR, " at %s\n", ctx.file.str().c_str());
            }
        }

        // wrap the function, performing the necessary pointer conversion

        Function *inner = f;
        inner->setName(ir_name + ".inner");

        FunctionType *wrapper_ft = FunctionType::get(rettype, argtypes, false);
        Function *wrapper =
            Function::Create(wrapper_ft, inner->getLinkage(), ir_name, *Mod);

        wrapper->copyAttributesFrom(inner);
        inner->addFnAttr(Attribute::AlwaysInline);

        BasicBlock *entry = BasicBlock::Create(ctx.builder.getContext(), "", wrapper);
        IRBuilder<> irbuilder(entry);
        SmallVector<Value *, 0> wrapper_args;
        for (size_t i = 0; i < nargt; ++i) {
            code_value_t *tti = code_svecref(tt, i);
            Value *v = wrapper->getArg(i);
            if (code_is_cpointer_type(tti))
                v = irbuilder.CreatePtrToInt(v, ctx.types().T_size);
            wrapper_args.push_back(v);
        }
        Value *call = irbuilder.CreateCall(inner, wrapper_args);
        // check if void
        if (rettype->isVoidTy())
            irbuilder.CreateRetVoid();
        else {
            if (code_is_cpointer_type(rtt))
                call = irbuilder.CreateIntToPtr(call, ctx.types().T_ptr);
            irbuilder.CreateRet(call);
        }

        f = wrapper;
    }

    // verify the function type
    assert(f->getReturnType() == rettype);
    int i = 0;
    for (SmallVector<Type *, 0>::iterator it = argtypes.begin(); it != argtypes.end();
         ++it, ++i) {
        if (*it != f->getFunctionType()->getParamType(i)) {
            std::string message;
            raw_string_ostream stream(message);
            stream << "Malformed llvmcall: argument " << i + 1 << " type "
                   << *f->getFunctionType()->getParamType(i)
                   << " does not match expected argument type " << **it;
            emit_error(ctx, stream.str());
            return code_cgval_t();
        }
    }

    // copy module properties that should always match
    Mod->setTargetTriple(code_Module->getTargetTriple());
    Mod->setDataLayout(code_Module->getDataLayout());
    Mod->setStackProtectorGuard(code_Module->getStackProtectorGuard());
    Mod->setOverrideStackAlignment(code_Module->getOverrideStackAlignment());

    // verify the definition
    Function *def = Mod->getFunction(ir_name);
    assert(def);
    std::string message = "Malformed LLVM function: \n";
    raw_string_ostream stream(message);
    if (verifyFunction(*def, &stream)) {
        emit_error(ctx, stream.str());
        JL_GC_POP();
        return code_cgval_t();
    }
    def->setLinkage(GlobalVariable::LinkOnceODRLinkage);

    // generate a call
    FunctionType *decl_typ = FunctionType::get(rettype, argtypes, def->isVarArg());
    Function *decl = Function::Create(decl_typ, def->getLinkage(), def->getAddressSpace(),
                                      def->getName(), code_Module);
    decl->setAttributes(def->getAttributes());
    CallInst *inst = ctx.builder.CreateCall(decl, argvals);

    // save the module to be linked later.
    // we cannot do this right now, because linking mutates the destination module,
    // which might invalidate LLVM values cached in cgval_t's (specifically constant arrays)
    ctx.llvmcall_modules.push_back(std::move(Mod));

    JL_GC_POP();

    if (inst->getType() != rettype) {
        std::string message;
        raw_string_ostream stream(message);
        stream << "Malformed llvmcall: return type " << *inst->getType()
               << " does not match declared return type" << *rettype;
        emit_error(ctx, stream.str());
        return code_cgval_t();
    }

    return mark_code_type(ctx, inst, retboxed, rtt);
}

// --- code generator for ccall itself ---

// Returns ctx.types().T_prcodevalue
static Value *box_ccall_result(code_codectx_t &ctx, Value *result, Value *runtime_dt, code_value_t *rt)
{
    // XXX: need to handle parameterized zero-byte types (singleton)
    const DataLayout &DL = ctx.builder.GetInsertBlock()->getModule()->getDataLayout();
    unsigned nb = DL.getTypeStoreSize(result->getType());
    unsigned align = sizeof(void*); // Allocations are at least pointer aligned
    MDNode *tbaa = code_is_mutable(rt) ? ctx.tbaa().tbaa_mutab : ctx.tbaa().tbaa_immut;
    Value *strct = emit_allocobj(ctx, nb, runtime_dt, true, align);
    setName(ctx.emission_context, strct, "ccall_result_box");
    init_bits_value(ctx, strct, result, tbaa);
    return strct;
}

static code_cgval_t mark_or_box_ccall_result(code_codectx_t &ctx, Value *result, bool isboxed, code_value_t *rt, code_unionall_t *unionall, bool static_rt)
{
    if (!static_rt) {
        assert(!isboxed && code_is_datatype(rt) && ctx.spvals_ptr && unionall);
        Value *runtime_dt = runtime_apply_type_env(ctx, rt);
        // TODO: skip this check if rt is not a Tuple
        emit_concretecheck(ctx, runtime_dt, "ccall: return type must be a concrete DataType");
        Value *strct = box_ccall_result(ctx, result, runtime_dt, rt);
        return mark_code_type(ctx, strct, true, rt); // TODO: code_rewrap_unionall(rt, unionall)
    }
    return mark_code_type(ctx, result, isboxed, rt);
}

class function_sig_t {
public:
    SmallVector<Type*, 0> fargt; // vector of llvm output types (code_struct_to_llvm) for arguments
    SmallVector<Type*, 0> fargt_sig; // vector of ABI coercion types for call signature
    SmallVector<bool, 0> fargt_isboxed; // vector of whether the llvm output type is a Code-box for each argument
    SmallVector<bool, 0> byRefList; // vector of "byref" parameters
    AttributeList attributes; // vector of function call site attributes
    Type *lrt; // input parameter of the llvm return type (from code_struct_to_llvm)
    bool retboxed; // input parameter indicating whether lrt is code_value_t*
    Type *prt; // out parameter of the llvm return type for the function signature
    int sret; // out parameter for indicating whether return value has been moved to the first argument position
    std::string err_msg;
    CallingConv::ID cc; // calling convention ABI
    bool llvmcall;
    code_svec_t *at; // svec of code argument types
    code_value_t *rt; // code return type
    code_unionall_t *unionall_env; // UnionAll environment for `at` and `rt`
    size_t nccallargs; // number of actual arguments
    size_t nreqargs; // number of required arguments in ccall function definition
    code_codegen_params_t *ctx;

    function_sig_t(const char *fname, Type *lrt, code_value_t *rt, bool retboxed, code_svec_t *at, code_unionall_t *unionall_env, size_t nreqargs, CallingConv::ID cc, bool llvmcall, code_codegen_params_t *ctx)
      : lrt(lrt), retboxed(retboxed),
        prt(NULL), sret(0), cc(cc), llvmcall(llvmcall),
        at(at), rt(rt), unionall_env(unionall_env),
        nccallargs(code_svec_len(at)), nreqargs(nreqargs),
        ctx(ctx)
    {
        err_msg = generate_func_sig(fname);
    }

    FunctionType *functype(LLVMContext &ctxt) const {
        assert(err_msg.empty());
        if (nreqargs > 0)
            return FunctionType::get(sret ? getVoidTy(ctxt) : prt, ArrayRef<Type*>(fargt_sig).slice(0, nreqargs), true);
        else
            return FunctionType::get(sret ? getVoidTy(ctxt) : prt, fargt_sig, false);
    }

    code_cgval_t emit_a_ccall(
            code_codectx_t &ctx,
            const native_sym_arg_t &symarg,
            code_cgval_t *argv,
            SmallVectorImpl<Value*> &gc_uses,
            bool static_rt) const;

private:
std::string generate_func_sig(const char *fname)
{
    assert(rt && !code_is_abstract_ref_type(rt));

    SmallVector<AttributeSet, 0> paramattrs;
    std::unique_ptr<AbiLayout> abi;
    if (llvmcall)
        abi.reset(new ABI_LLVMLayout());
    else
        abi.reset(new DefaultAbiState());
    sret = 0;
    LLVMContext &LLVMCtx = lrt->getContext();
    if (type_is_ghost(lrt)) {
        prt = lrt = getVoidTy(LLVMCtx);
        abi->use_sret(code_nothing_type, LLVMCtx);
    }
    else {
        if (retboxed || code_is_cpointer_type(rt) || lrt->isPointerTy()) {
            prt = lrt; // passed as pointer
            abi->use_sret(code_voidpointer_type, LLVMCtx);
        }
        else if (abi->use_sret((code_datatype_t*)rt, LLVMCtx)) {
            AttrBuilder retattrs(LLVMCtx);
            if (!ctx->TargetTriple.isOSWindows()) {
                // llvm used to use the old mingw ABI, skipping this marking works around that difference
                retattrs.addStructRetAttr(lrt);
            }
            retattrs.addAttribute(Attribute::NoAlias);
            paramattrs.push_back(AttributeSet::get(LLVMCtx, retattrs));
            fargt_sig.push_back(PointerType::get(lrt, 0));
            sret = 1;
            prt = lrt;
        }
        else {
            prt = abi->preferred_llvm_type((code_datatype_t*)rt, true, LLVMCtx);
            if (prt == NULL)
                prt = lrt;
        }
    }

    for (size_t i = 0; i < nccallargs; ++i) {
        AttrBuilder ab(LLVMCtx);
        code_value_t *tti = code_svecref(at, i);
        Type *t = NULL;
        bool isboxed;
        if (code_is_abstract_ref_type(tti)) {
            tti = (code_value_t*)code_voidpointer_type;
            t = getPointerTy(LLVMCtx);
            isboxed = false;
        }
        else if (llvmcall && code_is_llvmpointer_type(tti)) {
            t = bitstype_to_llvm(tti, LLVMCtx, true);
            tti = (code_value_t*)code_voidpointer_type;
            isboxed = false;
        }
        else {
            t = _code_struct_to_llvm(ctx, LLVMCtx, tti, &isboxed, llvmcall);
            if (t == getVoidTy(LLVMCtx)) {
                return make_errmsg(fname, i + 1, " type doesn't correspond to a C type");
            }
            if (code_is_primitivetype(tti) && t->isIntegerTy()) {
                // see pull req #978. need to annotate signext/zeroext for
                // small integer arguments.
                code_datatype_t *bt = (code_datatype_t*)tti;
                if (code_datatype_size(bt) < 4) {
                    if (code_signed_type && code_subtype(tti, (code_value_t*)code_signed_type))
                        ab.addAttribute(Attribute::SExt);
                    else
                        ab.addAttribute(Attribute::ZExt);
                }
            }
        }

        Type *pat;
        // n.b. `Array` used as argument type just passes a code object reference
        if (!code_is_datatype(tti) || ((code_datatype_t*)tti)->layout == NULL || code_is_array_type(tti) || code_is_layout_opaque(((code_datatype_t*)tti)->layout)) {
            tti = (code_value_t*)code_voidpointer_type; // passed as pointer
        }

        // Whether or not LLVM wants us to emit a pointer to the data
        assert(t && "LLVM type should not be null");
        bool byRef = abi->needPassByRef((code_datatype_t*)tti, ab, LLVMCtx, t);

        if (code_is_cpointer_type(tti)) {
            pat = t;
        }
        else if (byRef) {
            pat = PointerType::get(t, AddressSpace::Derived);
        }
        else {
            pat = abi->preferred_llvm_type((code_datatype_t*)tti, false, LLVMCtx);
            if (pat == NULL)
                pat = t;
        }

        if (!byRef && nreqargs > 0 && i >= nreqargs) { // TODO: handle byRef case too?
            // The C vararg ABI says that small types must get widened,
            // but we don't really want to expect the user to know that,
            // so attempt to do that coercion here
            if (!llvmcall && cc == CallingConv::C) {
                if (pat->isIntegerTy() && pat->getPrimitiveSizeInBits() < sizeof(int) * 8)
                    pat = getInt32Ty(lrt->getContext());
                if (pat->isFloatingPointTy() && pat->getPrimitiveSizeInBits() < sizeof(double) * 8)
                    pat = getDoubleTy(lrt->getContext());
                ab.removeAttribute(Attribute::SExt);
                ab.removeAttribute(Attribute::ZExt);
            }
        }

        byRefList.push_back(byRef);
        fargt.push_back(t);
        fargt_isboxed.push_back(isboxed);
        fargt_sig.push_back(pat);
        paramattrs.push_back(AttributeSet::get(LLVMCtx, ab));
    }

    AttributeSet FnAttrs;
    AttributeSet RetAttrs;
    // If return value is boxed it must be non-null.
    if (retboxed)
        RetAttrs = RetAttrs.addAttribute(LLVMCtx, Attribute::NonNull);
    if (rt == code_bottom_type)
        FnAttrs = FnAttrs.addAttribute(LLVMCtx, Attribute::NoReturn);
    assert(attributes.isEmpty());
    attributes = AttributeList::get(LLVMCtx, FnAttrs, RetAttrs, paramattrs);
    return "";
}
};

static std::pair<CallingConv::ID, bool> convert_cconv(code_sym_t *lhd)
{
    // check for calling convention specifier
    if (lhd == code_symbol("stdcall")) {
        return std::make_pair(CallingConv::X86_StdCall, false);
    }
    else if (lhd == code_symbol("cdecl") || lhd == code_symbol("ccall")) {
        // `ccall` calling convention is a placeholder for when there isn't one provided
        // it is not by itself a valid calling convention name to be specified in the surface
        // syntax.
        return std::make_pair(CallingConv::C, false);
    }
    else if (lhd == code_symbol("fastcall")) {
        return std::make_pair(CallingConv::X86_FastCall, false);
    }
    else if (lhd == code_symbol("thiscall")) {
        return std::make_pair(CallingConv::X86_ThisCall, false);
    }
    else if (lhd == code_symbol("llvmcall")) {
        return std::make_pair(CallingConv::C, true);
    }
    code_errorf("ccall: invalid calling convention %s", code_symbol_name(lhd));
}

static bool verify_ref_type(code_codectx_t &ctx, code_value_t* ref, code_unionall_t *unionall_env, int n, const char *fname)
{
    // emit verification that the tparam for Ref isn't Any or a TypeVar
    const char rt_err_msg_notany[] = " type Ref{Any} is invalid. Use Any or Ptr{Any} instead.";
    if (ref == (code_value_t*)code_any_type && n == 0) {
        emit_error(ctx, make_errmsg(fname, n, rt_err_msg_notany));
        return false;
    }
    else if (code_is_typevar(ref)) {
        bool always_error = true;
        if (unionall_env) {
            int i;
            code_unionall_t *ua = unionall_env;
            for (i = 0; code_is_unionall(ua); i++) {
                if (ua->var == (code_tvar_t*)ref) {
                    code_cgval_t runtime_sp = emit_sparam(ctx, i);
                    if (n > 0) {
                        always_error = false;
                    }
                    else if (runtime_sp.constant) {
                        if (runtime_sp.constant != (code_value_t*)code_any_type)
                            always_error = false;
                    }
                    else {
                        Value *notany = ctx.builder.CreateICmpNE(
                                boxed(ctx, runtime_sp),
                                track_pcodevalue(ctx, literal_pointer_val(ctx, (code_value_t*)code_any_type)));
                        setName(ctx.emission_context, notany, "any_type.not");
                        error_unless(ctx, notany, make_errmsg(fname, n, rt_err_msg_notany));
                        always_error = false;
                    }
                    break;
                }
                ua = (code_unionall_t*)ua->body;
            }
        }
        if (always_error) {
            emit_error(ctx, make_errmsg(fname, n, " type Ref should have an element type, not Ref{<:T}."));
            return false;
        }
    }
    return true;
}

static const std::string verify_ccall_sig(code_value_t *&rt, code_value_t *at,
                                          code_unionall_t *unionall_env, code_svec_t *sparam_vals,
                                          code_codegen_params_t *ctx,
                                          Type *&lrt, LLVMContext &ctxt,
                                          bool &retboxed, bool &static_rt, bool llvmcall=false)
{
    JL_TYPECHK(ccall, type, rt);
    JL_TYPECHK(ccall, simplevector, at);

    if (rt == (code_value_t*)code_any_type || code_is_array_type(rt) || code_is_genericmemory_type(rt) ||
            (code_is_datatype(rt) && ((code_datatype_t*)rt)->layout != NULL &&
             code_is_layout_opaque(((code_datatype_t*)rt)->layout))) {
        // n.b. `Array` used as return type just returns a code object reference
        lrt = CodeType::get_prcodevalue_ty(ctxt);
        retboxed = true;
    }
    else {
        // code_type_mappable_to_c should have already ensured that these are valid
        assert(code_is_structtype(rt) || code_is_primitivetype(rt) || rt == (code_value_t*)code_bottom_type);
        lrt = _code_struct_to_llvm(ctx, ctxt, rt, &retboxed, llvmcall);
        assert(!retboxed);
        if (CountTrackedPointers(lrt).count != 0)
            return "return type struct fields cannot contain a reference";
    }

    // is return type fully statically known?
    if (unionall_env == NULL) {
        static_rt = true;
    }
    else {
        static_rt = retboxed || !code_has_typevar_from_unionall(rt, unionall_env);
        if (!static_rt && sparam_vals != NULL && code_svec_len(sparam_vals) > 0) {
            rt = code_instantiate_type_in_env(rt, unionall_env, code_svec_data(sparam_vals));
            // `rt` is gc-rooted by the caller
            static_rt = true;
        }
    }

    return "";
}

const int fc_args_start = 6;

// Expr(:foreigncall, pointer, rettype, (argtypes...), nreq, [cconv | (cconv, effects)], args..., roots...)
static code_cgval_t emit_ccall(code_codectx_t &ctx, code_value_t **args, size_t nargs)
{
    JL_NARGSV(ccall, 5);
    args -= 1;
    code_value_t *rt = args[2];
    code_value_t *at = args[3];
    size_t nccallargs = code_svec_len(at);
    size_t nreqargs = code_unbox_long(args[4]); // if vararg
    assert(code_is_quotenode(args[5]));
    code_value_t *codecc = code_quotenode_value(args[5]);
    code_sym_t *cc_sym = NULL;
    if (code_is_symbol(codecc)) {
        cc_sym = (code_sym_t*)codecc;
    }
    else if (code_is_tuple(codecc)) {
        cc_sym = (code_sym_t*)code_get_nth_field_noalloc(codecc, 0);
    }
    assert(code_is_symbol(cc_sym));
    native_sym_arg_t symarg = {};
    JL_GC_PUSH3(&rt, &at, &symarg.gcroot);

    CallingConv::ID cc = CallingConv::C;
    bool llvmcall = false;
    std::tie(cc, llvmcall) = convert_cconv(cc_sym);

    interpret_symbol_arg(ctx, symarg, args[1], /*ccall=*/true, llvmcall);
    Value *&code_ptr = symarg.code_ptr;
    void (*&fptr)(void) = symarg.fptr;
    const char *&f_name = symarg.f_name;
    const char *&f_lib = symarg.f_lib;

    if (f_name == NULL && fptr == NULL && code_ptr == NULL) {
        if (symarg.gcroot != NULL) { // static_eval(ctx, args[1]) could not be interpreted to a function pointer
            const char *errmsg = invalid_symbol_err_msg(/*ccall=*/true);
            code_cgval_t arg1 = emit_expr(ctx, args[1]);
            emit_type_error(ctx, arg1, literal_pointer_val(ctx, (code_value_t *)code_pointer_type), errmsg);
        } else {
            emit_error(ctx, "ccall: null function pointer");
        }
        JL_GC_POP();
        return code_cgval_t();
    }

    auto _is_libcode_func = [&] (uintptr_t ptr, StringRef name) {
        if ((uintptr_t)fptr == ptr)
            return true;
        if (f_lib) {
            if ((f_lib == JL_EXE_LIBNAME) || // preventing invalid pointer access
                (f_lib == JL_LIBCODE_INTERNAL_DL_LIBNAME) ||
                (f_lib == JL_LIBCODE_DL_LIBNAME)) {
                // libcode-like
            }
            else
#ifdef _OS_WINDOWS_
            if (strcmp(f_lib, code_crtdll_basename) == 0) {
                // libcode-like
            }
            else
#endif
            return false;
        }
        return f_name && f_name == name;
    };
#define is_libcode_func(name) _is_libcode_func((uintptr_t)&(name), StringRef(XSTR(name)))

    // emit arguments
    SmallVector<code_cgval_t, 4> argv(nccallargs);
    for (size_t i = 0; i < nccallargs; i++) {
        // Code (expression) value of current parameter
        assert(i < nccallargs && i + fc_args_start <= nargs);
        code_value_t *argi = args[fc_args_start + i];
        argv[i] = emit_expr(ctx, argi);
        if (argv[i].typ == code_bottom_type) {
            JL_GC_POP();
            return code_cgval_t();
        }
    }

    // emit roots
    SmallVector<Value*> gc_uses;
    for (size_t i = nccallargs + fc_args_start; i <= nargs; i++) {
        // Code (expression) value of current parameter gcroot
        code_value_t *argi_root = args[i];
        if (code_is_long(argi_root))
            continue;
        code_cgval_t arg_root = emit_expr(ctx, argi_root);
        gc_uses.append(get_gc_roots_for(ctx, arg_root));
    }

    code_unionall_t *unionall = (code_is_method(ctx.linfo->def.method) && code_is_unionall(ctx.linfo->def.method->sig))
        ? (code_unionall_t*)ctx.linfo->def.method->sig
        : NULL;

    if (code_is_abstract_ref_type(rt)) {
        if (!verify_ref_type(ctx, code_tparam0(rt), unionall, 0, "ccall")) {
            JL_GC_POP();
            return code_cgval_t();
        }
        rt = (code_value_t*)code_any_type; // convert return type to code_value_t*
    }

    // some sanity checking and check whether there's a vararg
    Type *lrt;
    bool retboxed;
    bool static_rt;
    std::string err = verify_ccall_sig(
      /* inputs:  */
      rt, at, unionall,
      ctx.spvals_ptr == NULL ? ctx.linfo->sparam_vals : NULL,
      &ctx.emission_context,
      /* outputs: */
      lrt, ctx.builder.getContext(),
      retboxed, static_rt,
      /* optional arguments */
      llvmcall);
    if (err.empty()) {
        // some extra checks for ccall
        if (!retboxed && static_rt) {
            if (!code_is_concrete_type(rt)) {
                if (code_is_cpointer_type(rt))
                    err = "return type Ptr should have an element type (not Ptr{<:T})";
                else if (rt != code_bottom_type)
                    err = "return type must be a concrete DataType";
            }
        }
        assert(code_svec_len(at) >= nreqargs);
    }
    if (!err.empty()) {
        emit_error(ctx, "ccall " + err);
        JL_GC_POP();
        return code_cgval_t();
    }
    if (rt != args[2] && rt != (code_value_t*)code_any_type)
        rt = code_ensure_rooted(ctx, rt);
    function_sig_t sig("ccall", lrt, rt, retboxed,
                       (code_svec_t*)at, unionall, nreqargs,
                       cc, llvmcall, &ctx.emission_context);
    for (size_t i = 0; i < nccallargs; i++) {
        code_value_t *tti = code_svecref(at, i);
        if (code_is_abstract_ref_type(tti)) {
            if (!verify_ref_type(ctx, code_tparam0(tti), unionall, i + 1, "ccall")) {
                JL_GC_POP();
                return code_cgval_t();
            }
        }
    }

    // some special functions
    bool isVa = nreqargs > 0;
    (void)isVa; // prevent compiler warning
    if (is_libcode_func(code_value_ptr)) {
        ++CCALL_STAT(code_value_ptr);
        assert(retboxed ? lrt == ctx.types().T_prcodevalue : lrt == ctx.types().T_ptr);
        assert(!isVa && !llvmcall && nccallargs == 1);
        code_value_t *tti = code_svecref(at, 0);
        Type *largty;
        bool isboxed;
        if (code_is_abstract_ref_type(tti)) {
            tti = (code_value_t*)code_voidpointer_type;
            largty = ctx.types().T_ptr;
            isboxed = false;
        }
        else {
            largty = _code_struct_to_llvm(&ctx.emission_context, ctx.builder.getContext(), tti, &isboxed, llvmcall);
        }
        Value *retval;
        if (isboxed) {
            retval = boxed(ctx, argv[0]);
            retval = emit_pointer_from_objref(ctx, retval /*T_prcodevalue*/);
        }
        else {
            retval = emit_unbox(ctx, largty, argv[0], tti);
        }
        // retval is now an untracked code_value_t*
        if (retboxed)
            // WARNING: this addrspace cast necessarily implies that the value is rooted elsewhere!
            retval = ctx.builder.CreateAddrSpaceCast(retval, ctx.types().T_prcodevalue);
        JL_GC_POP();
        return mark_or_box_ccall_result(ctx, retval, retboxed, rt, unionall, static_rt);
    }
    else if (is_libcode_func(code_cpu_pause)||is_libcode_func(code_cpu_suspend)) {
        ++CCALL_STAT(code_cpu_pause);
        // Keep in sync with the code_threads.h version
        assert(lrt == getVoidTy(ctx.builder.getContext()));
        assert(!isVa && !llvmcall && nccallargs == 0);
#ifdef __MIC__
    //TODO
#else
        if (ctx.emission_context.TargetTriple.isX86()) {
            auto pauseinst = InlineAsm::get(FunctionType::get(getVoidTy(ctx.builder.getContext()), false), "pause",
                                                "~{memory}", true);
            ctx.builder.CreateCall(pauseinst);
            JL_GC_POP();
            return ghostValue(ctx, code_nothing_type);
        } else if (ctx.emission_context.TargetTriple.isAArch64()
                    || (ctx.emission_context.TargetTriple.isARM()
                        && ctx.emission_context.TargetTriple.getSubArch() != Triple::SubArchType::NoSubArch
                        // ARMv7 and above is < armv6
                        && ctx.emission_context.TargetTriple.getSubArch() < Triple::SubArchType::ARMSubArch_v6)) {
            InlineAsm* wait_inst;
            if (is_libcode_func(code_cpu_pause))
                wait_inst = InlineAsm::get(FunctionType::get(getVoidTy(ctx.builder.getContext()), false), "isb",
                                                "~{memory}", true);
            else
                wait_inst = InlineAsm::get(FunctionType::get(getVoidTy(ctx.builder.getContext()), false), "wfe",
                                                "~{memory}", true);
            ctx.builder.CreateCall(wait_inst);
            JL_GC_POP();
            return ghostValue(ctx, code_nothing_type);
        } else {
            JL_GC_POP();
            return ghostValue(ctx, code_nothing_type);
        }
#endif
    }
    else if (is_libcode_func(code_cpu_wake)) {
        ++CCALL_STAT(code_cpu_wake);
        // Keep in sync with the code_threads.h version
        assert(lrt == getVoidTy(ctx.builder.getContext()));
        assert(!isVa && !llvmcall && nccallargs == 0);
#if JL_CPU_WAKE_NOOP == 1
        JL_GC_POP();
        return ghostValue(ctx, code_nothing_type);
#endif
        if (ctx.emission_context.TargetTriple.isAArch64()
            || (ctx.emission_context.TargetTriple.isARM()
                && ctx.emission_context.TargetTriple.getSubArch() != Triple::SubArchType::NoSubArch
                // ARMv7 and above is < armv6
                && ctx.emission_context.TargetTriple.getSubArch() < Triple::SubArchType::ARMSubArch_v6)) {
            auto sevinst = InlineAsm::get(FunctionType::get(getVoidTy(ctx.builder.getContext()), false), "sev",
                                                "~{memory}", true);
            ctx.builder.CreateCall(sevinst);
            JL_GC_POP();
            return ghostValue(ctx, code_nothing_type);
        }
    }
    else if (is_libcode_func(code_gc_safepoint)) {
        ++CCALL_STAT(code_gc_safepoint);
        assert(lrt == getVoidTy(ctx.builder.getContext()));
        assert(!isVa && !llvmcall && nccallargs == 0);
        JL_GC_POP();
        ctx.builder.CreateCall(prepare_call(gcroot_flush_func));
        emit_gc_safepoint(ctx.builder, ctx.types().T_size, get_current_ptls(ctx), ctx.tbaa().tbaa_const);
        return ghostValue(ctx, code_nothing_type);
    }
    else if (is_libcode_func("code_get_ptls_states")) {
        ++CCALL_STAT(code_get_ptls_states);
        assert(lrt == ctx.types().T_size);
        assert(!isVa && !llvmcall && nccallargs == 0);
        JL_GC_POP();
        return mark_or_box_ccall_result(ctx, get_current_ptls(ctx), retboxed, rt, unionall, static_rt);
    }
    else if (is_libcode_func(code_threadid)) {
        ++CCALL_STAT(code_threadid);
        assert(lrt == getInt16Ty(ctx.builder.getContext()));
        assert(!isVa && !llvmcall && nccallargs == 0);
        JL_GC_POP();
        Value *ptask = get_current_task(ctx);
        const int tid_offset = offsetof(code_task_t, tid);
        Value *ptid = ctx.builder.CreateInBoundsGEP(getInt8Ty(ctx.builder.getContext()), ptask, ConstantInt::get(ctx.types().T_size, tid_offset / sizeof(int8_t)));
        setName(ctx.emission_context, ptid, "thread_id_ptr");
        LoadInst *tid = ctx.builder.CreateAlignedLoad(getInt16Ty(ctx.builder.getContext()), ptid, Align(sizeof(int16_t)));
        setName(ctx.emission_context, tid, "thread_id");
        code_aliasinfo_t ai = code_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_gcframe);
        ai.decorateInst(tid);
        return mark_or_box_ccall_result(ctx, tid, retboxed, rt, unionall, static_rt);
    }
    else if (is_libcode_func(code_get_tls_world_age)) {
        bool toplevel = !(ctx.linfo && code_is_method(ctx.linfo->def.method));
        if (!toplevel) { // top level code does not see a stable world age during execution
            ++CCALL_STAT(code_get_tls_world_age);
            assert(lrt == ctx.types().T_size);
            assert(!isVa && !llvmcall && nccallargs == 0);
            JL_GC_POP();
            Instruction *world_age = cast<Instruction>(ctx.world_age_at_entry);
            setName(ctx.emission_context, world_age, "task_world_age");
            code_aliasinfo_t ai = code_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_gcframe);
            ai.decorateInst(world_age);
            return mark_or_box_ccall_result(ctx, world_age, retboxed, rt, unionall, static_rt);
        }
    }
    else if (is_libcode_func(code_gc_disable_finalizers_internal)
#ifdef NDEBUG
             || is_libcode_func(code_gc_enable_finalizers_internal)
#endif
             ) {
        JL_GC_POP();
        Value *ptls_p = get_current_ptls(ctx);
        const int finh_offset = offsetof(code_tls_states_t, finalizers_inhibited);
        Value *pfinh = ctx.builder.CreateInBoundsGEP(getInt8Ty(ctx.builder.getContext()), ptls_p, ConstantInt::get(ctx.types().T_size, finh_offset / sizeof(int8_t)));
        setName(ctx.emission_context, pfinh, "finalizers_inhibited_ptr");
        LoadInst *finh = ctx.builder.CreateAlignedLoad(getInt32Ty(ctx.builder.getContext()), pfinh, Align(sizeof(int32_t)));
        setName(ctx.emission_context, finh, "finalizers_inhibited");
        Value *newval;
        if (is_libcode_func(code_gc_disable_finalizers_internal)) {
            newval = ctx.builder.CreateAdd(finh, ConstantInt::get(getInt32Ty(ctx.builder.getContext()), 1));
            setName(ctx.emission_context, newval, "finalizers_inhibited_inc");
        }
        else {
            newval = ctx.builder.CreateSelect(ctx.builder.CreateICmpEQ(finh, ConstantInt::get(getInt32Ty(ctx.builder.getContext()), 0)),
                                              ConstantInt::get(getInt32Ty(ctx.builder.getContext()), 0),
                                              ctx.builder.CreateSub(finh, ConstantInt::get(getInt32Ty(ctx.builder.getContext()), 1)));
            setName(ctx.emission_context, newval, "finalizers_inhibited_dec");
        }
        ctx.builder.CreateStore(newval, pfinh);
        return ghostValue(ctx, code_nothing_type);
    }
    else if (is_libcode_func(code_get_current_task)) {
        ++CCALL_STAT(code_get_current_task);
        assert(lrt == ctx.types().T_prcodevalue);
        assert(!isVa && !llvmcall && nccallargs == 0);
        JL_GC_POP();
        auto ct = track_pcodevalue(ctx, get_current_task(ctx));
        return mark_or_box_ccall_result(ctx, ct, retboxed, rt, unionall, static_rt);
    }
    else if (is_libcode_func(code_set_next_task)) {
        ++CCALL_STAT(code_set_next_task);
        assert(lrt == getVoidTy(ctx.builder.getContext()));
        assert(!isVa && !llvmcall && nccallargs == 1);
        JL_GC_POP();
        Value *ptls_pv = get_current_ptls(ctx);
        const int nt_offset = offsetof(code_tls_states_t, next_task);
        Value *pnt = ctx.builder.CreateInBoundsGEP(ctx.types().T_pcodevalue, ptls_pv, ConstantInt::get(ctx.types().T_size, nt_offset / sizeof(void*)));
        setName(ctx.emission_context, pnt, "next_task_ptr");
        ctx.builder.CreateStore(emit_pointer_from_objref(ctx, boxed(ctx, argv[0])), pnt);
        return ghostValue(ctx, code_nothing_type);
    }
    else if (is_libcode_func(code_sigatomic_begin)) {
        ++CCALL_STAT(code_sigatomic_begin);
        assert(lrt == getVoidTy(ctx.builder.getContext()));
        assert(!isVa && !llvmcall && nccallargs == 0);
        JL_GC_POP();
        ctx.builder.CreateCall(prepare_call(gcroot_flush_func));
        Value *pdefer_sig = emit_defer_signal(ctx);
        setName(ctx.emission_context, pdefer_sig, "defer_signal_ptr");
        Value *defer_sig = ctx.builder.CreateLoad(ctx.types().T_sigatomic, pdefer_sig);
        setName(ctx.emission_context, defer_sig, "defer_signal");
        defer_sig = ctx.builder.CreateAdd(defer_sig, ConstantInt::get(ctx.types().T_sigatomic, 1));
        setName(ctx.emission_context, defer_sig, "defer_signal_inc");
        ctx.builder.CreateStore(defer_sig, pdefer_sig);
        emit_signal_fence(ctx);
        return ghostValue(ctx, code_nothing_type);
    }
    else if (is_libcode_func(code_sigatomic_end)) {
        ++CCALL_STAT(code_sigatomic_end);
        assert(lrt == getVoidTy(ctx.builder.getContext()));
        assert(!isVa && !llvmcall && nccallargs == 0);
        JL_GC_POP();
        ctx.builder.CreateCall(prepare_call(gcroot_flush_func));
        Value *pdefer_sig = emit_defer_signal(ctx);
        setName(ctx.emission_context, pdefer_sig, "defer_signal_ptr");
        Value *defer_sig = ctx.builder.CreateLoad(ctx.types().T_sigatomic, pdefer_sig);
        setName(ctx.emission_context, defer_sig, "defer_signal");
        emit_signal_fence(ctx);
        error_unless(ctx,
                ctx.builder.CreateICmpNE(defer_sig, ConstantInt::get(ctx.types().T_sigatomic, 0)),
                "sigatomic_end called in non-sigatomic region");
        defer_sig = ctx.builder.CreateSub(
                defer_sig,
                ConstantInt::get(ctx.types().T_sigatomic, 1));
        setName(ctx.emission_context, defer_sig, "defer_signal_dec");
        ctx.builder.CreateStore(defer_sig, pdefer_sig);
        BasicBlock *checkBB = BasicBlock::Create(ctx.builder.getContext(), "check",
                                                 ctx.f);
        BasicBlock *contBB = BasicBlock::Create(ctx.builder.getContext(), "cont");
        auto not_deferred = ctx.builder.CreateICmpEQ(defer_sig, ConstantInt::get(ctx.types().T_sigatomic, 0));
        setName(ctx.emission_context, not_deferred, "deferred.not");
        ctx.builder.CreateCondBr(
                not_deferred,
                checkBB, contBB);
        ctx.builder.SetInsertPoint(checkBB);
        auto signal_page_load = ctx.builder.CreateLoad(
                ctx.types().T_size,
                ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_size,
                    get_current_signal_page_from_ptls(ctx.builder, ctx.types().T_size, get_current_ptls(ctx), ctx.tbaa().tbaa_const), -1),
                true);
        setName(ctx.emission_context, signal_page_load, "signal_page_load");
        ctx.builder.CreateBr(contBB);
        contBB->insertInto(ctx.f);
        ctx.builder.SetInsertPoint(contBB);
        return ghostValue(ctx, code_nothing_type);
    }
    else if (is_libcode_func(code_string_ptr)) {
        ++CCALL_STAT(code_string_ptr);
        assert(lrt == ctx.types().T_ptr);
        assert(!isVa && !llvmcall && nccallargs == 1);
        auto obj = emit_pointer_from_objref(ctx, boxed(ctx, argv[0])); // T_pprcodevalue
        // The inbounds gep makes it more clear to LLVM that the resulting value is not
        // a null pointer.
        auto strp = ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_prcodevalue, obj, 1);
        setName(ctx.emission_context, strp, "string_ptr");
        JL_GC_POP();
        return mark_or_box_ccall_result(ctx, strp, retboxed, rt, unionall, static_rt);
    }
    else if (is_libcode_func(code_symbol_name)) {
        ++CCALL_STAT(code_symbol_name);
        assert(lrt == ctx.types().T_ptr);
        assert(!isVa && !llvmcall && nccallargs == 1);
        auto obj = emit_pointer_from_objref(ctx, boxed(ctx, argv[0])); // T_pprcodevalue
        // The inbounds gep makes it more clear to LLVM that the resulting value is not
        // a null pointer.
        auto strp = ctx.builder.CreateConstInBoundsGEP1_32(
            ctx.types().T_prcodevalue, obj, (sizeof(code_sym_t) + sizeof(void*) - 1) / sizeof(void*));
        setName(ctx.emission_context, strp, "symbol_name");
        JL_GC_POP();
        return mark_or_box_ccall_result(ctx, strp, retboxed, rt, unionall, static_rt);
    }
    else if (is_libcode_func(code_genericmemory_owner) || is_libcode_func(icode_genericmemory_owner)) {
        ++CCALL_STAT(code_genericmemory_owner);
        assert(lrt == ctx.types().T_prcodevalue);
        assert(!isVa && !llvmcall && nccallargs == 1);
        Value *obj = emit_genericmemoryowner(ctx, boxed(ctx, argv[0]));
        JL_GC_POP();
        return mark_code_type(ctx, obj, true, code_any_type);
    }
    else if (is_libcode_func(code_alloc_genericmemory)) {
        ++CCALL_STAT(code_alloc_genericmemory);
        assert(lrt == ctx.types().T_prcodevalue);
        assert(!isVa && !llvmcall && nccallargs == 2);
        const code_cgval_t &typ = argv[0];
        const code_cgval_t &nel = argv[1];
        auto arg_typename = [&] JL_NOTSAFEPOINT {
            auto istyp = argv[0].constant;
            std::string type_str;
            if (istyp && code_is_datatype(istyp) && code_is_genericmemory_type(istyp)){
                auto eltype = code_tparam1(istyp);
                if (code_is_datatype(eltype))
                    type_str = code_symbol_name(((code_datatype_t*)eltype)->name->name);
                else if (code_is_uniontype(eltype))
                    type_str = "Union";
                else
                    type_str = "<unknown type>";
            }
            else
                type_str = "<unknown type>";
            return "Memory{" + type_str + "}[]";
            };
        auto alloc = ctx.builder.CreateCall(prepare_call(code_allocgenericmemory), { boxed(ctx,typ), emit_unbox(ctx, ctx.types().T_size, nel, (code_value_t*)code_ulong_type)});
        setName(ctx.emission_context, alloc, arg_typename);
        JL_GC_POP();
        return mark_code_type(ctx, alloc, true, code_any_type);
    }
    else if (is_libcode_func(memcpy) && (rt == (code_value_t*)code_nothing_type || code_is_cpointer_type(rt))) {
        ++CCALL_STAT(memcpy);
        const code_cgval_t &dst = argv[0];
        const code_cgval_t &src = argv[1];
        const code_cgval_t &n = argv[2];
        Value *destp = emit_unbox(ctx, ctx.types().T_ptr, dst, (code_value_t*)code_voidpointer_type);

        ctx.builder.CreateMemCpy(
                destp,
                MaybeAlign(1),
                emit_unbox(ctx, ctx.types().T_ptr, src, (code_value_t*)code_voidpointer_type),
                MaybeAlign(1),
                emit_unbox(ctx, ctx.types().T_size, n, (code_value_t*)code_ulong_type),
                false);
        JL_GC_POP();
        return rt == (code_value_t*)code_nothing_type ? ghostValue(ctx, code_nothing_type) :
            mark_or_box_ccall_result(ctx, destp, retboxed, rt, unionall, static_rt);
    }
    else if (is_libcode_func(memset) && (rt == (code_value_t*)code_nothing_type || code_is_cpointer_type(rt))) {
        ++CCALL_STAT(memset);
        const code_cgval_t &dst = argv[0];
        const code_cgval_t &val = argv[1];
        const code_cgval_t &n = argv[2];
        Value *destp = emit_unbox(ctx, ctx.types().T_ptr, dst, (code_value_t*)code_voidpointer_type);
        Value *val32 = emit_unbox(ctx, getInt32Ty(ctx.builder.getContext()), val, (code_value_t*)code_uint32_type);
        Value *val8 = ctx.builder.CreateTrunc(val32, getInt8Ty(ctx.builder.getContext()), "memset_val");
        ctx.builder.CreateMemSet(
            destp,
            val8,
            emit_unbox(ctx, ctx.types().T_size, n, (code_value_t*)code_ulong_type),
            MaybeAlign(1)
        );
        JL_GC_POP();
        return rt == (code_value_t*)code_nothing_type ? ghostValue(ctx, code_nothing_type) :
            mark_or_box_ccall_result(ctx, destp, retboxed, rt, unionall, static_rt);
    }
    else if (is_libcode_func(memmove) && (rt == (code_value_t*)code_nothing_type || code_is_cpointer_type(rt))) {
        ++CCALL_STAT(memmove);
        const code_cgval_t &dst = argv[0];
        const code_cgval_t &src = argv[1];
        const code_cgval_t &n = argv[2];
        Value *destp = emit_unbox(ctx, ctx.types().T_ptr, dst, (code_value_t*)code_voidpointer_type);

        ctx.builder.CreateMemMove(
                destp,
                MaybeAlign(0),
                emit_unbox(ctx, ctx.types().T_ptr, src, (code_value_t*)code_voidpointer_type),
                MaybeAlign(0),
                emit_unbox(ctx, ctx.types().T_size, n, (code_value_t*)code_ulong_type),
                false);
        JL_GC_POP();
        return rt == (code_value_t*)code_nothing_type ? ghostValue(ctx, code_nothing_type) :
            mark_or_box_ccall_result(ctx, destp, retboxed, rt, unionall, static_rt);
    }
    else if (is_libcode_func(code_object_id) && nccallargs == 1 &&
            rt == (code_value_t*)code_ulong_type) {
        ++CCALL_STAT(code_object_id);
        code_cgval_t val = argv[0];
        if (val.typ == (code_value_t*)code_symbol_type) {
            JL_GC_POP();
            const int hash_offset = offsetof(code_sym_t, hash);
            Value *ph1 = decay_derived(ctx, boxed(ctx, val));
            Value *ph2 = ctx.builder.CreateInBoundsGEP(ctx.types().T_size, ph1, ConstantInt::get(ctx.types().T_size, hash_offset / ctx.types().sizeof_ptr));
            setName(ctx.emission_context, ph2, "object_id_ptr");
            LoadInst *hashval = ctx.builder.CreateAlignedLoad(ctx.types().T_size, ph2, ctx.types().alignof_ptr);
            setName(ctx.emission_context, hashval, "object_id");
            code_aliasinfo_t ai = code_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_const);
            ai.decorateInst(hashval);
            return mark_or_box_ccall_result(ctx, hashval, retboxed, rt, unionall, static_rt);
        }
        else if (!val.isboxed) {
            // If the value is not boxed, try to compute the object id without
            // reboxing it.
            auto T_p_derived = PointerType::get(ctx.builder.getContext(), AddressSpace::Derived);
            if (!val.isghost && !val.ispointer())
                val = value_to_pointer(ctx, val);
            Value *args[] = {
                emit_typeof(ctx, val, false, true),
                val.isghost ? ConstantPointerNull::get(T_p_derived) :
                        decay_derived(ctx, data_pointer(ctx, val))
            };
            Value *ret = ctx.builder.CreateCall(prepare_call(code_object_id__func), ArrayRef<Value*>(args));
            setName(ctx.emission_context, ret, "object_id");
            JL_GC_POP();
            return mark_or_box_ccall_result(ctx, ret, retboxed, rt, unionall, static_rt);
        }
    }

    code_cgval_t retval = sig.emit_a_ccall(
            ctx,
            symarg,
            argv.data(),
            gc_uses,
            static_rt);
    JL_GC_POP();
    return retval;
}

code_cgval_t function_sig_t::emit_a_ccall(
        code_codectx_t &ctx,
        const native_sym_arg_t &symarg,
        code_cgval_t *argv,
        SmallVectorImpl<Value*> &gc_uses,
        bool static_rt) const
{
    ++EmittedCCalls;
    if (!err_msg.empty()) {
        emit_error(ctx, err_msg);
        return code_cgval_t();
    }

    FunctionType *functype = this->functype(ctx.builder.getContext());

    SmallVector<Value *, 8> argvals(nccallargs + sret);
    for (size_t ai = 0; ai < nccallargs; ai++) {
        // Current C function parameter
        code_cgval_t &arg = argv[ai];
        code_value_t *jargty = code_svecref(at, ai); // Code type of the current parameter
        Type *largty = fargt[ai]; // LLVM type of the current parameter
        bool toboxed = fargt_isboxed[ai];
        Type *pargty = fargt_sig[ai + sret]; // LLVM coercion type
        bool byRef = byRefList[ai]; // Argument attributes

        // if we know the function sparams, try to fill those in now
        // so that the code_to_native type checks are more likely to be doable (e.g. concrete types) at compile-time
        code_value_t *jargty_in_env = jargty;
        if (ctx.spvals_ptr == NULL && !toboxed && unionall_env && code_has_typevar_from_unionall(jargty, unionall_env) &&
                code_svec_len(ctx.linfo->sparam_vals) > 0) {
            jargty_in_env = code_instantiate_type_in_env(jargty_in_env, unionall_env, code_svec_data(ctx.linfo->sparam_vals));
            if (jargty_in_env != jargty)
                jargty_in_env = code_ensure_rooted(ctx, jargty_in_env);
        }

        Value *v;
        if (code_is_abstract_ref_type(jargty)) {
            if (!code_is_cpointer_type(arg.typ)) {
                emit_cpointercheck(ctx, arg, "ccall: argument to Ref{T} is not a pointer");
                arg.typ = (code_value_t*)code_voidpointer_type;
                arg.isboxed = false;
            }
            jargty_in_env = (code_value_t*)code_voidpointer_type;
        }

        v = code_to_native(ctx, largty, toboxed, jargty_in_env, unionall_env, arg, byRef, ai);
        bool issigned = code_signed_type && code_subtype(jargty, (code_value_t*)code_signed_type);
        if (byRef) {
            v = decay_derived(ctx, v);
            // code_to_native should already have done the alloca and store
            assert(v->getType() == pargty);
        }
        else {
            v = llvm_type_rewrite(ctx, v, pargty, issigned);
        }

        if (isa<UndefValue>(v)) {
            return code_cgval_t();
        }
        assert(v->getType() == pargty);
        argvals[ai + sret] = v;
    }

    Value *result = NULL;
    //This is only needed if !retboxed && srt && !coderetboxed
    Type *sretty = nullptr;
    // First, if the ABI requires us to provide the space for the return
    // argument, allocate the box and store that as the first argument type
    bool sretboxed = false;
    if (sret) {
        assert(!retboxed && code_is_datatype(rt) && "sret return type invalid");
        if (code_is_pointerfree(rt)) {
            result = emit_static_alloca(ctx, lrt);
            setName(ctx.emission_context, result, "ccall_sret");
            sretty = lrt;
            argvals[0] = result;
        }
        else {
            // XXX: result needs to be zero'd and given a GC root here
            // and has incorrect write barriers.
            // instead this code path should behave like `unsafe_load`
            result = emit_allocobj(ctx, (code_datatype_t*)rt, true);
            setName(ctx.emission_context, result, "ccall_sret_box");
            sretty = ctx.types().T_codevalue;
            sretboxed = true;
            gc_uses.push_back(result);
            argvals[0] = emit_pointer_from_objref(ctx, result);
        }
    }

    // make LLVM function object for the target
    // keep this close to the function call, so that the compiler can
    // optimize the global pointer load in the common case
    Value *llvmf;
    if (llvmcall) {
        ++EmittedLLVMCalls;
        if (symarg.code_ptr != NULL) {
            emit_error(ctx, "llvmcall doesn't support dynamic pointers");
            return code_cgval_t();
        }
        else if (symarg.fptr != NULL) {
            emit_error(ctx, "llvmcall doesn't support static pointers");
            return code_cgval_t();
        }
        else if (symarg.f_lib != NULL) {
            emit_error(ctx, "llvmcall doesn't support dynamic libraries");
            return code_cgval_t();
        }
        else {
            assert(symarg.f_name != NULL);
            StringRef f_name(symarg.f_name);
            bool f_extern = f_name.consume_front("extern ");
            llvmf = NULL;
            if (f_extern) {
                llvmf = code_Module->getOrInsertFunction(f_name, functype).getCallee();
                if (!isa<Function>(llvmf) || cast<Function>(llvmf)->isIntrinsic() || cast<Function>(llvmf)->getFunctionType() != functype)
                    llvmf = NULL;
            }
            else if (f_name.startswith("llvm.")) {
                // compute and verify auto-mangling for intrinsic name
                auto ID = Function::lookupIntrinsicID(f_name);
                if (ID != Intrinsic::not_intrinsic) {
                    // Accumulate an array of overloaded types for the given intrinsic
                    // and compute the new name mangling schema
                    SmallVector<Type*, 4> overloadTys;
                    SmallVector<Intrinsic::IITDescriptor, 8> Table;
                    getIntrinsicInfoTableEntries(ID, Table);
                    ArrayRef<Intrinsic::IITDescriptor> TableRef = Table;
                    auto res = Intrinsic::matchIntrinsicSignature(functype, TableRef, overloadTys);
                    if (res == Intrinsic::MatchIntrinsicTypes_Match) {
                        bool matchvararg = !Intrinsic::matchIntrinsicVarArg(functype->isVarArg(), TableRef);
                        if (matchvararg) {
                            Function *intrinsic = Intrinsic::getDeclaration(code_Module, ID, overloadTys);
                            assert(intrinsic->getFunctionType() == functype);
                            if (intrinsic->getName() == f_name || Intrinsic::getBaseName(ID) == f_name)
                                llvmf = intrinsic;
                        }
                    }
                }
            }
            if (llvmf == NULL) {
                emit_error(ctx, "llvmcall only supports intrinsic calls");
                return code_cgval_t();
            }
        }
    }
    else if (symarg.code_ptr != NULL) {
        ++LiteralCCalls;
        null_pointer_check(ctx, symarg.code_ptr, nullptr);
        llvmf = symarg.code_ptr;
    }
    else if (symarg.fptr != NULL) {
        ++LiteralCCalls;
        Type *funcptype = functype->getPointerTo(0);
        llvmf = literal_static_pointer_val((void*)(uintptr_t)symarg.fptr, funcptype);
        setName(ctx.emission_context, llvmf, "ccall_fptr");
        if (ctx.emission_context.imaging_mode)
            code_printf(JL_STDERR,"WARNING: literal address used in ccall for %s; code cannot be statically compiled\n", symarg.f_name);
    }
    else if (!ctx.params->use_codeplt) {
        if ((symarg.f_lib && !((symarg.f_lib == JL_EXE_LIBNAME) ||
              (symarg.f_lib == JL_LIBCODE_INTERNAL_DL_LIBNAME) ||
              (symarg.f_lib == JL_LIBCODE_DL_LIBNAME))) || symarg.lib_expr) {
            emit_error(ctx, "ccall: Had library expression, but symbol lookup was disabled");
        }
        llvmf = code_Module->getOrInsertFunction(symarg.f_name, functype).getCallee();
    }
    else {
        assert(symarg.f_name != NULL);
        PointerType *funcptype = PointerType::get(functype, 0);
        if (symarg.lib_expr) {
            ++DeferredCCallLookups;
            llvmf = runtime_sym_lookup(ctx, funcptype, NULL, symarg.lib_expr, symarg.f_name, ctx.f);
        }
        else /*if (ctx.emission_context.imaging) */{
            ++DeferredCCallLookups;
            // vararg requires musttail,
            // but musttail is incompatible with noreturn.
            if (functype->isVarArg())
                llvmf = runtime_sym_lookup(ctx, funcptype, symarg.f_lib, NULL, symarg.f_name, ctx.f);
            else
                llvmf = emit_plt(ctx, functype, attributes, cc, symarg.f_lib, symarg.f_name);
        }
    }

    OperandBundleDef OpBundle("code_roots", gc_uses);
    // the actual call
    CallInst *ret = ctx.builder.CreateCall(functype, llvmf,
            argvals,
            ArrayRef<OperandBundleDef>(&OpBundle, gc_uses.empty() ? 0 : 1));
    ((CallInst*)ret)->setAttributes(attributes);

    if (cc != CallingConv::C)
        ((CallInst*)ret)->setCallingConv(cc);
    if (!sret)
        result = ret; // no need to update sretty here because we know !sret
    if (0) { // Enable this to turn on SSPREQ (-fstack-protector) on the function containing this ccall
        ctx.f->addFnAttr(Attribute::StackProtectReq);
    }

    if (rt == code_bottom_type) {
        CreateTrap(ctx.builder);
        return code_cgval_t();
    }

    // Finally we need to box the result into code type
    // However, if we have already created a box for the return
    // type because the ABI required us to pass a pointer (sret),
    // then we do not need to do this.
    bool coderetboxed;
    if (retboxed) {
        assert(!sret);
        coderetboxed = true;
        ++RetBoxedCCalls;
    }
    else if (sret) {
        coderetboxed = sretboxed;
        if (!coderetboxed) {
            // something alloca'd above is SSA
            if (static_rt)
                return mark_code_slot(result, rt, NULL, ctx.tbaa().tbaa_stack);
            ++SRetCCalls;
            result = ctx.builder.CreateLoad(sretty, result);
            setName(ctx.emission_context, result, "returned");
        }
    }
    else {
        Type *codert = code_type_to_llvm(ctx, rt, &coderetboxed); // compute the real "coden" return type and compute whether it is boxed
        if (type_is_ghost(codert)) {
            return ghostValue(ctx, rt);
        }
        else if (code_is_datatype(rt) && code_is_datatype_singleton((code_datatype_t*)rt)) {
            return mark_code_const(ctx, ((code_datatype_t*)rt)->instance);
        }
        else if (coderetboxed && !retboxed) {
            assert(code_is_datatype(rt));
            if (static_rt) {
                Value *strct = emit_allocobj(ctx, (code_datatype_t*)rt, true);
                setName(ctx.emission_context, strct, "ccall_ret_box");
                MDNode *tbaa = code_is_mutable(rt) ? ctx.tbaa().tbaa_mutab : ctx.tbaa().tbaa_immut;
                int boxalign = code_alignment(rt);
                // copy the data from the return value to the new struct
                const DataLayout &DL = ctx.builder.GetInsertBlock()->getModule()->getDataLayout();
                auto resultTy = result->getType();
                size_t rtsz = code_datatype_size(rt);
                if (DL.getTypeStoreSize(resultTy) > rtsz) {
                    // ARM and AArch64 can use a LLVM type larger than the code type.
                    // When this happens, cast through memory.
                    auto slot = emit_static_alloca(ctx, resultTy);
                    setName(ctx.emission_context, slot, "type_pun_slot");
                    slot->setAlignment(Align(boxalign));
                    ctx.builder.CreateAlignedStore(result, slot, Align(boxalign));
                    code_aliasinfo_t ai = code_aliasinfo_t::fromTBAA(ctx, tbaa);
                    emit_memcpy(ctx, strct, ai, slot, ai, rtsz, boxalign, boxalign);
                }
                else {
                    init_bits_value(ctx, strct, result, tbaa, boxalign);
                }
                return mark_code_type(ctx, strct, true, rt);
            }
            coderetboxed = false; // trigger mark_or_box_ccall_result to build the runtime box
        }
        else if (lrt != prt) {
            assert(codert == lrt || !lrt->isStructTy()); // code_type_to_llvm and code_struct_to_llvm should be returning the same StructType
            result = llvm_type_rewrite(ctx, result, lrt, false);
        }
    }

    return mark_or_box_ccall_result(ctx, result, coderetboxed, rt, unionall_env, static_rt);
}

// Reset us back to codegen debug type
#undef DEBUG_TYPE
#define DEBUG_TYPE "code_irgen_codegen"
