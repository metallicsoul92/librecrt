#ifndef SYS_UTSNAME_H
#define SYS_UTSNAME_H

/**
 * @brief Defines the utsname structure and the uname function.
 *
 * This header provides the `utsname` structure, which holds system information, and the `uname` function to retrieve it.
 */

/**
 * @brief Structure representing system information.
 *
 * This structure holds various strings that provide information about the system, such as the operating system name and version.
 */
struct utsname {
    char sysname[65];  /**< Operating system name */
    char nodename[65]; /**< Network node hostname */
    char release[65];  /**< Operating system release */
    char version[65];  /**< Operating system version */
    char machine[65];  /**< Hardware identifier */
};

int uname(struct utsname *name); /**< Retrieves system information */

#endif // SYS_UTSNAME_H
