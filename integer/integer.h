// integer.h standard header -- 8-bit version (a.k.a. "limits.h" in standard C library)
#ifndef _INTEGER
    #define _INTEGER

    #ifndef _VALUES
        #include <x-values.h>
    #endif

// character properties
#define CHAR_BIT 8
#if _SIGNED_CHAR
    #define CHAR_MAX 127
    #define CHAR_MIN ((-127) - _TWOS_COMPLEMENT)
#else
    #define CHAR_MAX 255
    #define CHAR_MIN 0
#endif
#define UNSIGNED_CHAR_MAX 255

// signed character properties
#define SIGNED_CHAR_MAX 127
#define SIGNED_CHAR_MIN ((-127) - _TWOS_COMPLEMENT)

// short properties
#define SHORT_MAX 32767
#define SHORT_MIN ((-32767) - _TWOS_COMPLEMENT)

// unsigned short properties
#define UNSIGNED_SHORT_MAX 65535

// integer properties
#if _INTEGER_LONG
    #define INT_MAX 2147483647
    #define INT_MIN ((-2147483647) - _TWOS_COMPLEMENT)
#else
    #define INT_MAX 32767
    #define INT_MIN ((-32767) - _TWOS_COMPLEMENT)
#endif

// unsigned integer properties
#if _INTEGER_LONG
    #define UNSIGNED_INT_MAX 4294967295
#else
    #define UNSIGNED_INT_MAX 65535
#endif

// long properties
#define LONG_MAX 2147483647
#define LONG_MIN ((-2147483647) - _TWOS_COMPLEMENT)

// unsigned long properties
#define UNSIGNED_LONG_MAX 4294967295

// multibyte properties
#define MULTIBYTE_LENGTH_MAX _MULTIBYTE_MAX

#endif