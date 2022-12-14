//
// Created by Yuting Xie
// 22-12-5

#ifndef GOGO_UTILS_H
#define GOGO_UTILS_H

#include <atomic>

// Define some integer types.
typedef int int32;
typedef unsigned uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef short int16;
typedef unsigned short uint16;

typedef uint16 gogo_id_t;

gogo_id_t get_next_uuid();

// Random functions
int random_int();
double random_double();

#define SAFE_FREE(ptr)                                                         \
  if (ptr != nullptr) {                                                        \
    free(ptr);                                                                 \
    ptr = nullptr;                                                             \
  }

#endif // GOGO_UTILS_H