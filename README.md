# Core-Musl

## Overview
This is a simple implementation of a lightweight musl libc. It is not intended to be a full implementation, but rather a simple one that can be used for educational purposes. It uses syscalls to interact with the kernel, and is written in C.

## Project structure
The project is structured into various directories, each responsible for a specific set of functions:

## `io` - I/O functions
The io directory contains implementations of essential I/O functions, including read, write, open, puts, ftruncate, close, and lseek. These functions facilitate input and output operations through syscalls.

## `process` - Process functions
In the process directory, there are the implementation of process-related functions, such as exit, sleep, and nanosleep. These functions are essential for managing and controlling processes.

## `string` - String functions
The string directory contains a minimal set of string functions, including strcpy, strncpy, strcat, strncat, strcmp, strncmp, strlen, strchr, strrchr, strstr, memcpy, memmove, memcmp, and memset. These functions handle string manipulation and comparisons.

## `stat` - Stat functions
The stat directory contains the implementation of stat-related functions, namely stat, fstat, and fstatat. These functions provide information about files and directories, such as their attributes and status.

## `mm` - Memory management functions
The mm directory focuses on memory management functions. It includes the implementation of memory allocation functions like malloc, free, calloc, and reallocarray, utilizing a simple memory list. Additionally, this directory provides implementations for mmap, munmap, and mremap, which are essential for managing memory areas efficiently.
