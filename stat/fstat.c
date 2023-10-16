// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
  return fstatat(fd, "", st, AT_EMPTY_PATH);
}
