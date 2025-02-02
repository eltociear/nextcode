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

#define INTRINSICS \
    /*  wrap and unwrap */ \
    ADD_I(bitcast, 2) \
    /*  arithmetic */ \
    ADD_I(neg_int, 1) \
    ADD_I(add_int, 2) \
    ADD_I(sub_int, 2) \
    ADD_I(mul_int, 2) \
    ADD_I(sdiv_int, 2) \
    ADD_I(udiv_int, 2) \
    ADD_I(srem_int, 2) \
    ADD_I(urem_int, 2) \
    ADD_I(neg_float, 1) \
    ADD_I(add_float, 2) \
    ADD_I(sub_float, 2) \
    ADD_I(mul_float, 2) \
    ADD_I(div_float, 2) \
    ADD_I(fma_float, 3) \
    ADD_I(muladd_float, 3) \
    /*  fast arithmetic */ \
    ALIAS(neg_float_fast, neg_float) \
    ALIAS(add_float_fast, add_float) \
    ALIAS(sub_float_fast, sub_float) \
    ALIAS(mul_float_fast, mul_float) \
    ALIAS(div_float_fast, div_float) \
    /*  same-type comparisons */ \
    ADD_I(eq_int, 2) \
    ADD_I(ne_int, 2) \
    ADD_I(slt_int, 2) \
    ADD_I(ult_int, 2) \
    ADD_I(sle_int, 2) \
    ADD_I(ule_int, 2) \
    ADD_I(eq_float, 2) \
    ADD_I(ne_float, 2) \
    ADD_I(lt_float, 2) \
    ADD_I(le_float, 2) \
    ALIAS(eq_float_fast, eq_float) \
    ALIAS(ne_float_fast, ne_float) \
    ALIAS(lt_float_fast, lt_float) \
    ALIAS(le_float_fast, le_float) \
    ADD_I(fpiseq, 2) \
    /*  bitwise operators */ \
    ADD_I(and_int, 2) \
    ADD_I(or_int, 2) \
    ADD_I(xor_int, 2) \
    ADD_I(not_int, 1) \
    ADD_I(shl_int, 2) \
    ADD_I(lshr_int, 2) \
    ADD_I(ashr_int, 2) \
    ADD_I(bswap_int, 1) \
    ADD_I(ctpop_int, 1) \
    ADD_I(ctlz_int, 1) \
    ADD_I(cttz_int, 1) \
    /*  conversion */ \
    ADD_I(sext_int, 2) \
    ADD_I(zext_int, 2) \
    ADD_I(trunc_int, 2) \
    ADD_I(fptoui, 2) \
    ADD_I(fptosi, 2) \
    ADD_I(uitofp, 2) \
    ADD_I(sitofp, 2) \
    ADD_I(fptrunc, 2) \
    ADD_I(fpext, 2) \
    /*  checked arithmetic */ \
    ADD_I(checked_sadd_int, 2) \
    ADD_I(checked_uadd_int, 2) \
    ADD_I(checked_ssub_int, 2) \
    ADD_I(checked_usub_int, 2) \
    ADD_I(checked_smul_int, 2) \
    ADD_I(checked_umul_int, 2) \
    ADD_I(checked_sdiv_int, 2) \
    ADD_I(checked_udiv_int, 2) \
    ADD_I(checked_srem_int, 2) \
    ADD_I(checked_urem_int, 2) \
    /*  functions */ \
    ADD_I(abs_float, 1) \
    ADD_I(copysign_float, 2) \
    ADD_I(flipsign_int, 2) \
    ADD_I(ceil_llvm, 1) \
    ADD_I(floor_llvm, 1) \
    ADD_I(trunc_llvm, 1) \
    ADD_I(rint_llvm, 1) \
    ADD_I(sqrt_llvm, 1) \
    ADD_I(sqrt_llvm_fast, 1) \
    /*  pointer arithmetic */ \
    ADD_I(add_ptr, 2) \
    ADD_I(sub_ptr, 2) \
    /*  pointer access */ \
    ADD_I(pointerref, 3) \
    ADD_I(pointerset, 4) \
    /*  pointer atomics */ \
    ADD_I(atomic_fence, 1) \
    ADD_I(atomic_pointerref, 2) \
    ADD_I(atomic_pointerset, 3) \
    ADD_I(atomic_pointerswap, 3) \
    ADD_I(atomic_pointermodify, 4) \
    ADD_I(atomic_pointerreplace, 5) \
    /*  c interface */ \
    ADD_I(cglobal, 2) \
    ALIAS(llvmcall, llvmcall) \
    /*  cpu feature tests */ \
    ADD_I(have_fma, 1) \
    /*  hidden intrinsics */ \
    ADD_HIDDEN(cglobal_auto, 1)

enum intrinsic {
#define ADD_I(func, nargs) func,
#define ADD_HIDDEN ADD_I
#define ALIAS ADD_I
    INTRINSICS
#undef ADD_I
#undef ADD_HIDDEN
#undef ALIAS
    num_intrinsics
};
