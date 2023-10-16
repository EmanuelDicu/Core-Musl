// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
  size_t i;

  for (i = 0; source[i] != '\0'; ++i)
    destination[i] = source[i];
  destination[i] = '\0';

  return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
  size_t i;

  for (i = 0; i < len && source[i] != '\0'; ++i)
    destination[i] = source[i];
  for ( ; i < len; ++i)
    destination[i] = '\0';

  return destination;
}

char *strcat(char *destination, const char *source)
{
	size_t dest_len = strlen(destination);
  size_t i;

  for (i = 0; source[i] != '\0'; ++i)
    destination[dest_len + i] = source[i];
  destination[dest_len + i] = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
  size_t dest_len = strlen(destination);
  size_t i;

  for (i = 0; i < len && source[i] != '\0'; ++i)
    destination[dest_len + i] = source[i];
  destination[dest_len + i] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	size_t i = 0;

  for (i = 0; str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]; ++i)
    ;

  return (str1[i] == str2[i]) ? 0 : (str1[i] < str2[i]) ? -1 : 1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
  size_t i;

  for (i = 0; i < len && str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]; ++i)
    ;

  return (i == len || str1[i] == str2[i]) ? 0 : (str1[i] < str2[i]) ? -1 : 1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	size_t len = strlen(str);
  size_t i;

  for (i = 0; i < len && str[i] != c; ++i)
    ;

  return (i == len) ? NULL : (str + i);
}

char *strrchr(const char *str, int c)
{
	size_t len = strlen(str);
  size_t i;

  for (i = len; i > 0 && str[i - 1] != c; --i)
    ;

  return (i > 0) ? (str + i - 1) : NULL;
}

char *strstr(const char *haystack, const char *needle)
{
  size_t len_haystack = strlen(haystack);
  size_t len_leedle = strlen(needle);
	size_t i;
  size_t j;
  int ok;

  for (i = 0; i < len_haystack - len_leedle; ++i)
  {
    ok = 1;
    for (j = 0; ok && j < len_leedle; ++j)
    {
      if (haystack[i + j] != needle[j])
        ok = 0;
    }
    if (ok)
      return (haystack + i);
  }

  return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
  size_t len_haystack = strlen(haystack);
  size_t len_leedle = strlen(needle);
	size_t i;
  size_t j;
  int ok;

  for (i = len_haystack - len_leedle; i > 0; --i)
  {
    ok = 1;
    for (j = 0; ok && j < len_leedle; ++j)
    {
      if (haystack[i + j - 1] != needle[j])
        ok = 0;
    }
    if (ok)
      return (haystack + i - 1);
  }

  return NULL;
}

void *memcpy(void *vptr_destination, const void *vptr_source, size_t num)
{
	size_t i;
  char *destination = vptr_destination;
  const char *source = vptr_source;

  for (i = 0; i < num; ++i)
    destination[i] = source[i];

	return destination;
}

void *memmove(void *vptr_destination, const void *vptr_source, size_t num)
{
	size_t i;
  char *destination = vptr_destination;
  const char *source = vptr_source;

  if (destination < source)
  {
    for (i = 0; i < num; ++i)
      destination[i] = source[i];
  } else {
  if (source < destination)
    {
      for (i = num; i > 0; --i)
        destination[i - 1] = source[i - 1];
    }
  }

	return destination;
}

int memcmp(const void *void_ptr1, const void *void_ptr2, size_t num)
{
  size_t i;
	const char *ptr1 = void_ptr1;
  const char *ptr2 = void_ptr2;

  for (i = 0; i < num && ptr1[i] == ptr2[i]; ++i)
    ;

  return (i == num || ptr1[i] == ptr2[i]) ? 0 : (ptr1[i] < ptr2[i]) ? -1 : 1;
}

void *memset(void *void_ptr, int value, size_t num)
{
	size_t i;
  char *ptr = void_ptr;

  for (i = 0; i < num; ++i)
    ptr[i] = value;

  return void_ptr;
}
