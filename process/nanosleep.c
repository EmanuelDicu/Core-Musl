#include <internal/syscall.h>
#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
  int r = syscall(__NR_nanosleep, req, rem);
  if (r < 0)
  {
    errno = -r;
    return -1;
  }
  return 0;
}
