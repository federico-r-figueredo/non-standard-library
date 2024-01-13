/* test integer macros */
#include <integer.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
    // test basic properties of integer.h macros

    // char
    printf("     CHARACTER_BIT =       \t%2i\tMULTIBYTE_LENGTH =        \t%2i\n\n", CHAR_BIT, MULTIBYTE_LENGTH_MAX);
    printf("          CHAR_MAX = \t%10i\t        CHAR_MIN =  \t%10i\n\n", CHAR_MAX, CHAR_MIN);
    printf("   SIGNED_CHAR_MAX = \t%10i\t SIGNED_CHAR_MIN =  \t%10i\n\n", SIGNED_CHAR_MAX, SIGNED_CHAR_MIN);
    printf(" UNSIGNED_CHAR_MAX = \t%10u\n\n", UNSIGNED_CHAR_MAX);

    // short
    printf("         SHORT_MAX = \t%10i\t       SHORT_MIN =  \t%10i\n\n", SHORT_MAX, SHORT_MIN);
    printf("UNSIGNED_SHORT_MAX = \t%10u\n\n", UNSIGNED_SHORT_MAX);

    // int
    printf("           INT_MAX = \t%10i\t        INT_MIN =  \t%10i\n\n", INT_MAX, INT_MIN);
    printf("  UNSIGNED_INT_MAX = \t%10u\n\n", UNSIGNED_INT_MAX);

    // long
    printf("          LONG_MAX = \t%10i\t       LONG_MIN = \t%10i\n\n", LONG_MAX, LONG_MIN);
    printf(" UNSIGNED_LONG_MAX = \t%10lu\n\n", UNSIGNED_LONG_MAX);

    #if ((CHAR_BIT < 8) || (CHAR_MAX < 127) || (0 < CHAR_MIN) || (CHAR_MAX != SIGNED_CHAR_MAX) && (CHAR_MAX != UNSIGNED_CHAR_MAX))
        #error bad char properties
    #endif

    #if ((INT_MAX < 32767) || (-32767 < INT_MIN) || (INT_MAX < SHORT_MAX))
        #error bad int properties
    #endif

    #if ((LONG_MAX < 2147483647) || (-2147483647 < LONG_MIN) || (LONG_MAX < INT_MAX))
        #error bad long properties
    #endif

    #if (MULTIBYTE_LENGTH_MAX < 1)
        #error bad multibyte properties
    #endif

    #if ((SIGNED_CHAR_MAX < 127) || (-127 < SIGNED_CHAR_MIN))
        #error bad signed char properties
    #endif

    #if ((SHORT_MAX < 32767) || (-32767 < SHORT_MIN))
        #error bad short properties
    #endif

    #if (UNSIGNED_CHAR_MAX < 255 || (UNSIGNED_CHAR_MAX / 2) < SIGNED_CHAR_MAX)
        #error bad unsigned char properties
    #endif

    #if (UNSIGNED_INT_MAX < 255 || (UNSIGNED_INT_MAX / 2) < INT_MAX)
        #error bad unsigned int properties
    #endif

    #if (UNSIGNED_LONG_MAX < 4294967295) || ((UNSIGNED_LONG_MAX / 2) < LONG_MAX)
        #error bad unsigned long properties
    #endif

    #if ((UNSIGNED_SHORT_MAX < 65535) || ((UNSIGNED_SHORT_MAX / 2) < SHORT_MAX) || (UNSIGNED_SHORT_MAX < SHORT_MAX))
        #error bad unsigned short properties
    #endif

    puts("\033[32mSUCCESS testing <integer.h>");
    return EXIT_SUCCESS;
}