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

// This defines a bare-bones loader that opens `libjulia` and immediately invokes its `load_repl()` function.
#include "loader.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Bring in helper functions for windows without libgcc. */
#ifdef _OS_WINDOWS_
#include "loader_win_utils.c"
#endif

JULIA_DEFINE_FAST_TLS

#ifdef _COMPILER_ASAN_ENABLED_
LANGUAGE_DLLEXPORT const char* __asan_default_options(void)
{
    return "allow_user_segv_handler=1:detect_leaks=0";
    // FIXME: enable LSAN after fixing leaks & defining __lsan_default_suppressions(),
    //        or defining __lsan_default_options = exitcode=0 once publicly available
    //        (here and in flisp/flmain.c)
}
#endif

#ifdef _OS_WINDOWS_
int mainCRTStartup(void)
{
    int argc;
    LPWSTR * wargv = CommandLineToArgv(GetCommandLine(), &argc);
    char ** argv = (char **)malloc(sizeof(char*) * (argc + 1));
    setup_stdio();
#else
int main(int argc, char * argv[])
{
#endif

#if defined(_COMPILER_ASAN_ENABLED_) || defined(_COMPILER_TSAN_ENABLED_) || defined(_COMPILER_MSAN_ENABLED_)
    // ASAN/TSAN do not support RTLD_DEEPBIND
    // https://github.com/google/sanitizers/issues/611
    putenv("LBT_USE_RTLD_DEEPBIND=0");
#endif

    // Convert Windows wchar_t values to UTF8
#ifdef _OS_WINDOWS_
    for (int i = 0; i < argc; i++) {
        argv[i] = wchar_to_utf8(wargv[i]);
        if (!argv[i]) {
            jl_loader_print_stderr("Unable to convert all arguments to UTF-8!\n");
            return 1;
        }
    }
    argv[argc] = NULL;
#endif

    // Call load_repl with our initialization arguments:
    int ret = jl_load_repl(argc, argv);

    // On Windows we're running without the CRT that would do this for us
    exit(ret);
    return ret;
}

#if defined(__GLIBC__) && (defined(_COMPILER_ASAN_ENABLED_) || defined(_COMPILER_TSAN_ENABLED_))
// fork is generally bad news, but it is better if we prevent applications from
// making it worse as openblas threadpools cause it to hang
int __register_atfork232(void (*prepare)(void), void (*parent)(void), void (*child)(void), void *dso_handle) {
    return 0;
}
__asm__ (".symver __register_atfork232, __register_atfork@@GLIBC_2.3.2");
#endif

#ifdef __cplusplus
} // extern "C"
#endif
