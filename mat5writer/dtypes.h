#ifndef _DTYPES_H_
#define _DTYPES_H_

#ifdef __cplusplus
  #include <cstdint>
#else
  #include <stdint.h>
#endif

#ifdef __GNUC__

  typedef uint8_t  uint8;
  typedef uint8_t  u8;
  typedef uint16_t uint16;
  typedef uint16_t u16;
  
  //legacy code - can be removed due cstdint header
  #ifdef __x86_64__
    /*
    * LLP64/IL32P64 - e.g. Microsoft Windows (X64/IA-64)
    */
    typedef uint32_t uint32;
    typedef uint32_t u32;
  #else
    /*
    * LP64/I32LP64 - e.g. Most Unix and Unix-like systems, e.g. Solaris, Linux, and Mac OS X
    */
    typedef uint32_t uint32;
    typedef uint32_t u32;
  #endif
  typedef uint64_t uint64;
  typedef uint64_t u64;
  
  //-----
  
  typedef int8_t  int8;
  typedef int8_t  s8;
  typedef int16_t int16;
  typedef int16_t s16;
  
  //legacy code - can be removed due cstdint header
  #ifdef __x86_64__
    /*
    * LLP64/IL32P64 - e.g. Microsoft Windows (X64/IA-64)
    */
    typedef int32_t int32;
    typedef int32_t s32;
  #else
    /*
    * LP64/I32LP64 - e.g. Most Unix and Unix-like systems, e.g. Solaris, Linux, and Mac OS X
    */
    typedef int32_t int32;
    typedef int32_t s32;
  #endif
  typedef int64_t int64;
  typedef int64_t s64;

#else
    #error "Code was only verified with the GNU C Compiler"
#endif

#endif // DTYPES_H
