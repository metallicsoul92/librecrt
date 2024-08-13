#ifndef SYS_STAT_H
#define SYS_STAT_H

#ifndef __HAS_STDDEF
#include "../../crt/include/stddef.h"
#define __HAS_STDDEF
#endif

#ifndef __HAS_POSIX_SYS_TYPES
#include "types.h"
#define __HAS_POSIX_SYS_TYPES
#endif

// File type macros
#define S_IFMT  0170000  // type of file
#define S_IFDIR 0040000  // directory
#define S_IFCHR 0020000  // character special
#define S_IFBLK 0060000  // block special
#define S_IFREG 0100000  // regular file

// Permission macros
#define S_IRUSR 00400  // read permission, owner
#define S_IWUSR 00200  // write permission, owner
#define S_IXUSR 00100  // execute/search permission, owner

struct stat {
    mode_t st_mode;     // protection
    off_t st_size;      // total size, in bytes
    time_t st_atime;    // time of last access
    time_t st_mtime;    // time of last modification
    time_t st_ctime;    // time of last status change
};

int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int mkdir(const char *pathname, mode_t mode);

#endif // SYS_STAT_H
