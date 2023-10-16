#include <internal/io.h>
#include <internal/syscall.h>
#include <errno.h>
#include <string.h>

int puts(const char *s)
{
  int r1 = write(1, s, strlen(s));
  int r2 = write(1, "\n", 1);
  if (r1 < 0 || r2 < 0) {
    errno = -r1;
    return -1;
  }

  return 0;
}
