/* crt/src/locale.c */

#include "../include/locale.h"

/* Default C locale information (minimal implementation) */
static struct lconv default_lconv = {
    .decimal_point = ".",
    .thousands_sep = "",
    .grouping = "",
    .int_curr_symbol = "",
    .currency_symbol = "",
    .mon_decimal_point = "",
    .mon_thousands_sep = "",
    .mon_grouping = "",
    .positive_sign = "",
    .negative_sign = "",
    .int_frac_digits = "",
    .frac_digits = "",
    .p_cs_precedes = "",
    .p_sep_by_space = "",
    .n_cs_precedes = "",
    .n_sep_by_space = "",
    .p_sign_posn = "",
    .n_sign_posn = ""
};

/* Current locale category settings */
static char *current_locale = "C";

/**
 * @brief Sets or queries the program's current locale.
 *
 * @param category The category to set or query (LC_ALL, LC_NUMERIC, etc.).
 * @param locale The locale to set (NULL to query the current locale).
 * @return A string representing the current locale setting.
 */
char *setlocale(int category, const char *locale) {
    /* Minimal implementation: only supports "C" locale */
    if (locale == NULL || locale[0] == '\0') {
        return current_locale;  /* Return the current locale */
    }

    if (locale[0] == 'C' && locale[1] == '\0') {
        return current_locale;  /* Return "C" if "C" locale is requested */
    }

    return NULL;  /* Unsupported locale */
}

/**
 * @brief Returns a pointer to a structure with locale-specific information.
 *
 * @return A pointer to a `struct lconv` with locale-specific information.
 */
struct lconv *localeconv(void) {
    return &default_lconv;  /* Return the default "C" locale settings */
}
