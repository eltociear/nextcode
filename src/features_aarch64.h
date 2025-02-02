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

// Copy values `from arch/arm64/include/uapi/asm/hwcap.h` from linux kernel source tree
// and match LLVM names.
// See also https://www.kernel.org/doc/html/latest/arm64/elf_hwcaps.html

// LLVM features in `llvm/lib/Target/AArch64/AArch64.td`

// AArch64 features definition
// hwcap
// LANGUAGE_FEATURE_DEF(fp, 0, 0) // HWCAP_HP. Required
// LANGUAGE_FEATURE_DEF(asimd, 1, 0) // HWCAP_ASIMD. Required
// LANGUAGE_FEATURE_DEF(evtstrm, 2, 0) // HWCAP_EVTSTRM. Not needed
// LANGUAGE_FEATURE_DEF(aes, 3, 0) // HWCAP_AES. Implied by `aes`
LANGUAGE_FEATURE_DEF(aes, 4, 0) // HWCAP_PMULL, ID_AA64ISAR0_EL1.AES == 2
// LANGUAGE_FEATURE_DEF(sha1, 5, UINT32_MAX) // HWCAP_SHA1. Implied by `sha2`
LANGUAGE_FEATURE_DEF(sha2, 6, 0) // HWCAP_SHA2
LANGUAGE_FEATURE_DEF(crc, 7, 0) // HWCAP_CRC32. Required in ARMv8.1
LANGUAGE_FEATURE_DEF(lse, 8, 0) // HWCAP_ATOMICS, ARMv8.1-Atomics. Required in ARMv8.1
LANGUAGE_FEATURE_DEF(fullfp16, 9, 0) // HWCAP_FPHP
// LANGUAGE_FEATURE_DEF(asimdhp, 10, 0) // HWCAP_ASIMDHP. Same as `fullfp16`
// LANGUAGE_FEATURE_DEF(cpuid, 11, 0) // HWCAP_CPUID. Not needed
LANGUAGE_FEATURE_DEF(rdm, 12, 0) // HWCAP_ASIMDRDM, ARMv8.1-SIMD. Required in ARMv8.1
LANGUAGE_FEATURE_DEF(jsconv, 13, 0) // HWCAP_JSCVT. Required in ARMv8.3
LANGUAGE_FEATURE_DEF(complxnum, 14, 0) // HWCAP_FCMA. Required in ARMv8.3
LANGUAGE_FEATURE_DEF(rcpc, 15, 0) // HWCAP_LRCPC, ARMv8.3-RCPC. Required in ARMv8.3
LANGUAGE_FEATURE_DEF(ccpp, 16, 0) // HWCAP_DCPOP, ARMv8.2-DCPoP. Required in ARMv8.2
LANGUAGE_FEATURE_DEF(sha3, 17, 0) // HWCAP_SHA3. ARMv8.2-SHA
// LANGUAGE_FEATURE_DEF(sm3, 18, 0) // HWCAP_SM3. Same as `sm4`
LANGUAGE_FEATURE_DEF(sm4, 19, 0) // HWCAP_SM4, ARMv8.2-SM
LANGUAGE_FEATURE_DEF(dotprod, 20, 0) // HWCAP_ASIMDDP, ARMv8.2-DotProd
// LANGUAGE_FEATURE_DEF(sha512, 21, UINT32_MAX) // HWCAP_SHA512. Not implement in LLVM yet
LANGUAGE_FEATURE_DEF(sve, 22, 0) // HWCAP_SVE
LANGUAGE_FEATURE_DEF(fp16fml, 23, 0) // HWCAP_ASIMDFHM, ARMv8.2-FHM
LANGUAGE_FEATURE_DEF(dit, 24, 0) // HWCAP_DIT, ARMv8.4-DIT. Required in ARMv8.4
// LANGUAGE_FEATURE_DEF(uscat, 25, UINT32_MAX) // HWCAP_USCAT, ARMv8.4-LSE
LANGUAGE_FEATURE_DEF_NAME(rcpc_immo, 26, 0, "rcpc-immo") // HWCAP_ILRCPC, ARMv8.4-RCPC. Required in ARMv8.4
LANGUAGE_FEATURE_DEF(flagm, 27, 120000) // HWCAP_FLAGM, ARMv8.4-CondM. Required in ARMv8.4
LANGUAGE_FEATURE_DEF(ssbs, 28, 0) // HWCAP_SSBS
LANGUAGE_FEATURE_DEF(sb, 29, 0) // HWCAP_SB. Required in ARMv8.5
LANGUAGE_FEATURE_DEF(pauth, 30, 120000) // HWCAP_PACA
// LANGUAGE_FEATURE_DEF(pa, 31, 0) // HWCAP_PACG. Merged with `pauth`.

// hwcap2
LANGUAGE_FEATURE_DEF(ccdp, 32 + 0, 0) // HWCAP2_DCPODP, ARMv8.2-DCCVADP. Required in ARMv8.5
LANGUAGE_FEATURE_DEF(sve2, 32 + 1, 0) // HWCAP2_SVE2
// LANGUAGE_FEATURE_DEF_NAME(sve2_aes, 32 + 2, 0, "sve2-aes") // HWCAP2_SVEAES, Implied by `sve2-aes`
LANGUAGE_FEATURE_DEF_NAME(sve2_aes, 32 + 3, 0, "sve2-aes") // HWCAP2_SVEPMULL, ID_AA64ZFR0_EL1.AES == 2
LANGUAGE_FEATURE_DEF_NAME(sve2_bitperm, 32 + 4, 100000, "sve2-bitperm") // HWCAP2_SVEBITPERM
LANGUAGE_FEATURE_DEF_NAME(sve2_sha3, 32 + 5, 0, "sve2-sha3") // HWCAP2_SVESHA3
LANGUAGE_FEATURE_DEF_NAME(sve2_sm4, 32 + 6, 0, "sve2-sm4") // HWCAP2_SM4
LANGUAGE_FEATURE_DEF(altnzcv, 32 + 7, 0) // HWCAP2_FLAGM2, ARMv8.5-CondM. Required in ARMv8.5
LANGUAGE_FEATURE_DEF(fptoint, 32 + 8, 0) // HWCAP2_FRINT. Required in ARMv8.5
// LANGUAGE_FEATURE_DEF(svei8mm, 32 + 9, UINT32_MAX) // HWCAP2_SVEI8MM, ARMv8.2-I8MM. Same as `i8mm`
LANGUAGE_FEATURE_DEF(f32mm, 32 + 10, 110000) // HWCAP2_SVEF32MM, ARMv8.2-F32MM
LANGUAGE_FEATURE_DEF(f64mm, 32 + 11, 110000) // HWCAP2_SVEF64MM, ARMv8.2-F64MM
// LANGUAGE_FEATURE_DEF(svebf16, 32 + 12, UINT32_MAX) // HWCAP2_SVEBF16, ARMv8.2-BF16. Same as `bf16`
LANGUAGE_FEATURE_DEF(i8mm, 32 + 13, 110000) // HWCAP2_I8MM, ARMv8.2-I8MM. Required in ARMv8.6
LANGUAGE_FEATURE_DEF(bf16, 32 + 14, 110000) // HWCAP2_BF16, ARMv8.2-BF16. Required in ARMv8.6
// LANGUAGE_FEATURE_DEF(dgh, 32 + 15, UINT32_MAX) // HWCAP2_DGH, ARMv8.0-DGH. Not implement in LLVM yet
LANGUAGE_FEATURE_DEF(rand, 32 + 16, 0) // HWCAP2_RNG, ARMv8.5-RNG
LANGUAGE_FEATURE_DEF(bti, 32 + 17, 0) // HWCAP2_BTI
LANGUAGE_FEATURE_DEF(mte, 32 + 18, 0) // HWCAP2_MTE, ARMv8.5-MemTag (reserved as of kernel 5.9-rc1)

// custom bits to match llvm model
LANGUAGE_FEATURE_DEF(v8_1a, 32 * 2 + 0, 0)
LANGUAGE_FEATURE_DEF(v8_2a, 32 * 2 + 1, 0)
LANGUAGE_FEATURE_DEF(v8_3a, 32 * 2 + 2, 0)
LANGUAGE_FEATURE_DEF(v8_4a, 32 * 2 + 3, 0)
LANGUAGE_FEATURE_DEF(v8_5a, 32 * 2 + 4, 0)
LANGUAGE_FEATURE_DEF(v8_6a, 32 * 2 + 5, 110000)

// Missing LLVM features available at EL0:
//     tme: ID_AA64ISAR0_EL1.TME (0b1) (LLVM 10)
//     am: ID_AA64PFR0_EL1.AMU (0b1, 0b10)
//     specrestrict: ID_AA64PFR0_EL1.CSV2 (0b10)
//     predres: ID_AA64PFR0_EL1.CSV3 (0b1)
//     ecv: ID_AA64MMFR0_EL1.ECV (0b1, 0b10) (LLVM 11)
//     lor: ID_AA64MMFR1_EL1.LO (0b1)
//     perfmon: ID_AA64DFR0_EL1.PMUVer (0b1, 0b100, 0b101, 0b110)
//     spe: ID_AA64DFR0_EL1.PMSVer (0b1 or 0b10)
//     tracev8.4: ID_AA64DFR0_EL1.TraceFilt (0b1)
//     ete: ???
