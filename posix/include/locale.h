/* posix/include/locale.h */

#ifndef _POSIX_LOCALE_H
#define _POSIX_LOCALE_H

#ifndef __HAS_STDDEF
#include "../../crt/include/stddef.h"
#define __HAS_STDDEF
#endif

/* Locale category constants */
#define LC_ALL        0
#define LC_COLLATE    1
#define LC_CTYPE      2
#define LC_MONETARY   3
#define LC_NUMERIC    4
#define LC_TIME       5
#define LC_MESSAGES   6  // POSIX-specific category

/* Structure representing locale information */
struct lconv {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char *int_frac_digits;
    char *frac_digits;
    char *p_cs_precedes;
    char *p_sep_by_space;
    char *n_cs_precedes;
    char *n_sep_by_space;
    char *p_sign_posn;
    char *n_sign_posn;
};

/* Placeholder for locale_t type used in POSIX functions */
typedef void* locale_t;

/* Function declarations */
char *setlocale(int category, const char *locale);
struct lconv *localeconv(void);

/* POSIX-specific locale functions */
locale_t newlocale(int category_mask, const char *locale, locale_t base);
locale_t duplocale(locale_t loc);
void freelocale(locale_t loc);
locale_t uselocale(locale_t newloc);

#endif /* _POSIX_LOCALE_H */
