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

#ifdef _CPU_X86_
#define LANGUAGE_X86_64ONLY_VER(x) UINT32_MAX
#else
#define LANGUAGE_X86_64ONLY_VER(x) x
#endif

// X86 features definition
// EAX=1: ECX
LANGUAGE_FEATURE_DEF(sse3, 0, 0)
LANGUAGE_FEATURE_DEF(pclmul, 1, 0)
LANGUAGE_FEATURE_DEF(ssse3, 9, 0)
LANGUAGE_FEATURE_DEF(fma, 12, 0)
LANGUAGE_FEATURE_DEF(cx16, 13, LANGUAGE_X86_64ONLY_VER(0)) // cx16 requires 64bit
LANGUAGE_FEATURE_DEF_NAME(sse41, 19, 0, "sse4.1")
LANGUAGE_FEATURE_DEF_NAME(sse42, 20, 0, "sse4.2")
LANGUAGE_FEATURE_DEF(movbe, 22, 0)
LANGUAGE_FEATURE_DEF(popcnt, 23, 0)
LANGUAGE_FEATURE_DEF(aes, 25, 0)
LANGUAGE_FEATURE_DEF(xsave, 26, 0)
LANGUAGE_FEATURE_DEF(avx, 28, 0)
LANGUAGE_FEATURE_DEF(f16c, 29, 0)
LANGUAGE_FEATURE_DEF(rdrnd, 30, 0)

// EAX=1: EDX
// LANGUAGE_FEATURE_DEF(, 32 + ?, ????)

// EAX=7,ECX=0: EBX
LANGUAGE_FEATURE_DEF(fsgsbase, 32 * 2 + 0, 0)
// LANGUAGE_FEATURE_DEF(sgx, 32 * 2 + 2, 0) // Disable for now since it's very hard to detect
LANGUAGE_FEATURE_DEF(bmi, 32 * 2 + 3, 0)
// LANGUAGE_FEATURE_DEF(hle, 32 * 2 + 4, 0) // Not used and gone in LLVM 5.0
LANGUAGE_FEATURE_DEF(avx2, 32 * 2 + 5, 0)
LANGUAGE_FEATURE_DEF(bmi2, 32 * 2 + 8, 0)
// LANGUAGE_FEATURE_DEF(invpcid, 32 * 2 + 10, 0) // Privileged instruction
LANGUAGE_FEATURE_DEF(rtm, 32 * 2 + 11, 0)
// LANGUAGE_FEATURE_DEF(mpx, 32 * 2 + 14, 0) // Deprecated in LLVM 10.0
LANGUAGE_FEATURE_DEF(avx512f, 32 * 2 + 16, 0)
LANGUAGE_FEATURE_DEF(avx512dq, 32 * 2 + 17, 0)
LANGUAGE_FEATURE_DEF(rdseed, 32 * 2 + 18, 0)
LANGUAGE_FEATURE_DEF(adx, 32 * 2 + 19, 0)
// LANGUAGE_FEATURE_DEF(smap, 32 * 2 + 20, 0) // Not used and gone in LLVM 5.0
LANGUAGE_FEATURE_DEF(avx512ifma, 32 * 2 + 21, 0)
// LANGUAGE_FEATURE_DEF(pcommit, 32 * 2 + 22, 0) // Deprecated
LANGUAGE_FEATURE_DEF(clflushopt, 32 * 2 + 23, 0)
LANGUAGE_FEATURE_DEF(clwb, 32 * 2 + 24, 0)
LANGUAGE_FEATURE_DEF(avx512pf, 32 * 2 + 26, 0)
LANGUAGE_FEATURE_DEF(avx512er, 32 * 2 + 27, 0)
LANGUAGE_FEATURE_DEF(avx512cd, 32 * 2 + 28, 0)
LANGUAGE_FEATURE_DEF(sha, 32 * 2 + 29, 0)
LANGUAGE_FEATURE_DEF(avx512bw, 32 * 2 + 30, 0)
LANGUAGE_FEATURE_DEF(avx512vl, 32 * 2 + 31, 0)

// EAX=7,ECX=0: ECX
LANGUAGE_FEATURE_DEF(prefetchwt1, 32 * 3 + 0, 0)
LANGUAGE_FEATURE_DEF(avx512vbmi, 32 * 3 + 1, 0)
LANGUAGE_FEATURE_DEF(pku, 32 * 3 + 4, 0) // ospke
LANGUAGE_FEATURE_DEF(waitpkg, 32 * 3 + 5, 0)
LANGUAGE_FEATURE_DEF(avx512vbmi2, 32 * 3 + 6, 0)
LANGUAGE_FEATURE_DEF(shstk, 32 * 3 + 7, 0)
LANGUAGE_FEATURE_DEF(gfni, 32 * 3 + 8, 0)
LANGUAGE_FEATURE_DEF(vaes, 32 * 3 + 9, 0)
LANGUAGE_FEATURE_DEF(vpclmulqdq, 32 * 3 + 10, 0)
LANGUAGE_FEATURE_DEF(avx512vnni, 32 * 3 + 11, 0)
LANGUAGE_FEATURE_DEF(avx512bitalg, 32 * 3 + 12, 0)
LANGUAGE_FEATURE_DEF(avx512vpopcntdq, 32 * 3 + 14, 0)
LANGUAGE_FEATURE_DEF(rdpid, 32 * 3 + 22, 0)
LANGUAGE_FEATURE_DEF(cldemote, 32 * 3 + 25, 0)
LANGUAGE_FEATURE_DEF(movdiri, 32 * 3 + 27, 0)
LANGUAGE_FEATURE_DEF(movdir64b, 32 * 3 + 28, 0)
LANGUAGE_FEATURE_DEF(enqcmd, 32 * 3 + 29, 0)

// EAX=7,ECX=0: EDX
// LANGUAGE_FEATURE_DEF(avx5124vnniw, 32 * 4 + 2, ?????)
// LANGUAGE_FEATURE_DEF(avx5124fmaps, 32 * 4 + 3, ?????)
LANGUAGE_FEATURE_DEF(uintr, 32 * 4 + 5, 140000)
LANGUAGE_FEATURE_DEF(avx512vp2intersect, 32 * 4 + 8, 0)
LANGUAGE_FEATURE_DEF(serialize, 32 * 4 + 14, 110000)
LANGUAGE_FEATURE_DEF(tsxldtrk, 32 * 4 + 16, 110000)
LANGUAGE_FEATURE_DEF(pconfig, 32 * 4 + 18, 0)
LANGUAGE_FEATURE_DEF_NAME(amx_bf16, 32 * 4 + 22, 110000, "amx-bf16")
LANGUAGE_FEATURE_DEF(avx512fp16, 32 * 4 + 23, 140000)
LANGUAGE_FEATURE_DEF_NAME(amx_tile, 32 * 4 + 24, 110000, "amx-tile")
LANGUAGE_FEATURE_DEF_NAME(amx_int8, 32 * 4 + 25, 110000, "amx-int8")

// EAX=0x80000001: ECX
// ignore sahf on 32bit x86 since it is required
LANGUAGE_FEATURE_DEF(sahf, 32 * 5 + 0, LANGUAGE_X86_64ONLY_VER(0))
LANGUAGE_FEATURE_DEF(lzcnt, 32 * 5 + 5, 0)
LANGUAGE_FEATURE_DEF(sse4a, 32 * 5 + 6, 0)
LANGUAGE_FEATURE_DEF(prfchw, 32 * 5 + 8, 0)
LANGUAGE_FEATURE_DEF(xop, 32 * 5 + 11, 0)
// LANGUAGE_FEATURE_DEF(lwp, 32 * 5 + 15, 0) Deprecated
LANGUAGE_FEATURE_DEF(fma4, 32 * 5 + 16, 0)
LANGUAGE_FEATURE_DEF(tbm, 32 * 5 + 21, 0)
LANGUAGE_FEATURE_DEF(mwaitx, 32 * 5 + 29, 0)

// EAX=0x80000001: EDX
// 3dnow is here but we don't care...
// LANGUAGE_FEATURE_DEF(, 32 * 6 + ?, ?????)

// EAX=0xd: EAX
LANGUAGE_FEATURE_DEF(xsaveopt, 32 * 7 + 0, 0)
LANGUAGE_FEATURE_DEF(xsavec, 32 * 7 + 1, 0)
LANGUAGE_FEATURE_DEF(xsaves, 32 * 7 + 3, 0)

// EAX=0x80000008: EBX
LANGUAGE_FEATURE_DEF(clzero, 32 * 8 + 0, 0)
LANGUAGE_FEATURE_DEF(wbnoinvd, 32 * 8 + 9, 0)

// EAX=7,ECX=1: EAX
LANGUAGE_FEATURE_DEF(avxvnni, 32 * 9 + 4, 120000)
LANGUAGE_FEATURE_DEF(avx512bf16, 32 * 9 + 5, 0)

// EAX=0x14,ECX=0: EBX
LANGUAGE_FEATURE_DEF(ptwrite, 32 * 10 + 4, 0)

#undef LANGUAGE_X86_64ONLY_VER
