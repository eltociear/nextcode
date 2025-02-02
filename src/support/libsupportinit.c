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

#include <locale.h>
#include "libsupport.h"

#ifndef _OS_WINDOWS_
#include <sys/resource.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

static const char *language_strchrnul(const char *s, int c)
{
    char *p = strchr(s, c);
    if (p)
        return p;
    return s + strlen(s);
}

void libsupport_init(void)
{
    static int isInitialized = 0;
    if (!isInitialized) {
        ios_init_stdstreams();
        isInitialized = 1;
#ifndef _OS_WINDOWS_
        // Raise the open file descriptor limit.
        {
            struct rlimit rl;
            if (getrlimit(RLIMIT_NOFILE, &rl) == 0 && rl.rlim_cur != rl.rlim_max) {
                // Do a binary search for the limit.
                rlim_t min = rl.rlim_cur;
                rlim_t max = 1 << 20;
                // But if there's a defined upper bound, don't search, just set it.
                if (rl.rlim_max != RLIM_INFINITY) {
                    min = rl.rlim_max;
                    max = rl.rlim_max;
                }
                do {
                    rl.rlim_cur = min + (max - min) / 2;
                    if (setrlimit(RLIMIT_NOFILE, &rl)) {
                        max = rl.rlim_cur;
                    } else {
                        min = rl.rlim_cur;
                    }
                } while (min + 1 < max);
            }
        }
#endif
        // adopt the user's locale for most formatting
        setlocale(LC_ALL, "");
        // but use locale-independent numeric formats (for parsing)
        setlocale(LC_NUMERIC, "C");
        // and try to specify ASCII or UTF-8 (preferred) for our Libc and Cstring functions
        char *ctype = setlocale(LC_CTYPE, NULL);
        if (ctype) {
            size_t codeset = language_strchrnul(ctype, '.') - ctype;
            if (strncmp(ctype + codeset, ".UTF-8", strlen(".UTF-8")) == 0 ||
                strncmp(ctype + codeset, ".utf-8", strlen(".utf-8")) == 0 ||
                strncmp(ctype + codeset, ".utf8", strlen(".utf8")) == 0)
                return; // already UTF-8
            ctype = (char*)memcpy(malloc_s(codeset + sizeof(".UTF-8")), ctype, codeset);
            strcpy(ctype + codeset, ".UTF-8");
        }
        setlocale(LC_CTYPE, "C"); // ASCII
#ifndef _OS_WINDOWS_
        if (setlocale(LC_CTYPE, "C.UTF-8") == NULL && // Linux/FreeBSD name
            setlocale(LC_CTYPE, "en_US.UTF-8") == NULL && // Common name
            setlocale(LC_CTYPE, "UTF-8") == NULL && // Apple name
            (ctype == NULL || setlocale(LC_CTYPE, ctype) == NULL)) { // attempt to form it manually
            ios_puts("WARNING: failed to select UTF-8 encoding, using ASCII\n", ios_stderr);
        }
#endif
        if (ctype)
            free(ctype);
    }
}

#ifdef __cplusplus
}
#endif
