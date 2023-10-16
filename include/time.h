#ifndef __TIME_H__
#define __TIME_H__

#include <internal/types.h>

struct timespec
{
  int64_t tv_sec;
  uint32_t tv_nsec;
};

unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *req, struct timespec *rem);

#endif
