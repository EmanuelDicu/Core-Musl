// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
  return fstatat(AT_FDCWD, path, buf, 0);
}
