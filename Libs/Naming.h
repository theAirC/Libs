#pragma once

#include <stdint.h>

#define _JOIN(x,y) x##y
#define JOIN(x,y)  _JOIN(x,y)

typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef u8 byte;

#define MSb(x)      ((x) & ~(~0 >> 1))
#define LSb(x)      ((x) & 1)

#define asize(x)    (sizeof(x)/sizeof(x[0]))
