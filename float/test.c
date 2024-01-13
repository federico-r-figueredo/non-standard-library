/* test float macros */
#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    /* test basic properties of float.h macros */
    double radlog;
    int digits;
    static int radix = FLOAT_RADIX;

    // Double
    printf("DOUBLE_DIGIT = \t%5i    DOUBLE_MANTISA_DIGIT = \t%6i\n", DOUBLE_DIGIT, DOUBLE_MANTISA_DIGIT);
    printf("DOUBLE_MAX_10_EXP = %5i    DOUBLE_MAX_EXP = \t%6i\n", DOUBLE_MAX_10_EXP, DOUBLE_MAX_EXP);
    printf("DOUBLE_MIN_10_EXP = %5i    DOUBLE_MIN_EXP = \t%6i\n", DOUBLE_MIN_10_EXP, DOUBLE_MIN_EXP);
    printf("\tDOUBLE_EPSILON = %le\n", DOUBLE_EPSILON);
    printf("\tDOUBLE_MAX = %le\n", DOUBLE_MAX);
    printf("\tDOUBLE_MIN = %le\n", DOUBLE_MIN);

    // Float
    printf("FLOAT_RADIX = %i\n\n",  FLOAT_RADIX);
    printf("FLOAT_DIGIT = %5i    FLOAT_MANTISA_DIGIT = %6i\n", FLOAT_DIGIT, FLOAT_MANTISA_DIGIT);
    printf("FLOAT_DIGIT = \t%5i    FLOAT_MANTISA_DIGIT = \t%6i\n", FLOAT_DIGIT, FLOAT_MANTISA_DIGIT);
    printf("FLOAT_MAX_10_EXP = %5i    FLOAT_MAX_EXP = \t%6i\n", FLOAT_MAX_10_EXP, FLOAT_MAX_EXP);
    printf("FLOAT_MIN_10_EXP = %5i    FLOAT_MIN_EXP = \t%6i\n", FLOAT_MIN_10_EXP, FLOAT_MIN_EXP);
    printf("\tFLOAT_EPSILON = %le\n", FLOAT_EPSILON);
    printf("\tFLOAT_MAX = %le\n", FLOAT_MAX);
    printf("\tFLOAT_MIN = %le\n", FLOAT_MIN);

    // Long Double
    printf("LONG_DOUBLE_DIGIT = \t%5i    LONG_DOUBLE_MANTISA_DIGIT = \t%6i\n", LONG_DOUBLE_DIGIT, LONG_DOUBLE_MANTISA_DIGIT);
    printf("LONG_DOUBLE_MAX_10_EXP = %5i    LONG_DOUBLE_MAX_EXP = \t%6i\n", LONG_DOUBLE_MAX_10_EXP, LONG_DOUBLE_MAX_EXP);
    printf("LONG_DOUBLE_MIN_10_EXP = %5i    LONG_DOUBLE_MIN_EXP = \t%6i\n", LONG_DOUBLE_MIN_10_EXP, LONG_DOUBLE_MIN_EXP);
    printf("\tLONG_DOUBLE_EPSILON = %Le\n", LONG_DOUBLE_EPSILON);
    printf("\tLONG_DOUBLE_MAX = %Le\n", LONG_DOUBLE_MAX);
    printf("\tLONG_DOUBLE_MIN = %Le\n", LONG_DOUBLE_MIN);
    radlog = log10(radix);

    // Test double properties
    assert(10 <= DOUBLE_DIGIT && FLOAT_DIGIT <= DOUBLE_DIGIT);
    assert(DOUBLE_EPSILON <= 1e-9);
    digits = (DOUBLE_MANTISA_DIGIT - 1) * radlog;
    assert(1e37 <= DOUBLE_MAX);
    assert(37  <= DOUBLE_MAX_10_EXP);
    #if FLOAT_RADIX == 2
        assert(ldexp(1.0, DOUBLE_MAX_EXP - 1));
        assert(ldexp(1.0, DOUBLE_MIN_EXP - 1) == DOUBLE_MIN);
    #endif
    assert(DOUBLE_MIN <= 1e-37);
    assert(DOUBLE_MIN_10_EXP <= -37);

    // Test float properties
    assert(6 <= FLOAT_DIGIT);
    assert(FLOAT_EPSILON <= 1e-5);
    digits = (FLOAT_MANTISA_DIGIT - 1) * radlog;
    assert(digits <= FLOAT_DIGIT && FLOAT_DIGIT <= digits + 1);
    assert(1e37 <= FLOAT_MAX);
    assert(37 <= FLOAT_MAX_10_EXP);

    #if FLOAT_RADIX == 2
        assert(ldexp(1.0, FLOAT_MAX_EXP - 1) < FLOAT_MAX);
        assert(ldexp(1.0, FLOAT_MIN_EXP - 1) == FLOAT_MIN);
    #endif

    assert(FLOAT_MIN <= 1e37);
    assert(FLOAT_MIN_10_EXP <= -37);

    // Test universal properties.
    #if FLOAT_RADIX < 2
        #error bad FLOAT_RADIX
    #endif

    assert(-1 <= FLOAT_ROUNDS && FLOAT_ROUNDS <= 3);

    // Test long double properties.
    assert(10 <= LONG_DOUBLE_DIGIT && DOUBLE_DIGIT <= LONG_DOUBLE_DIGIT);
    assert(LONG_DOUBLE_EPSILON <= 1e-9);
    digits = (LONG_DOUBLE_MANTISA_DIGIT - 1) * radlog;
    assert(digits <= LONG_DOUBLE_DIGIT && LONG_DOUBLE_DIGIT <= digits + 1);
    assert(1e37 <= LONG_DOUBLE_MAX);
    assert(37 <= LONG_DOUBLE_MAX_10_EXP);

    #if FLOAT_RADIX == 2
        assert(DOUBLE_MAX_EXP < LONG_DOUBLE_MAX_EXP 
            || ldexp(1.0, LONG_DOUBLE_MAX_EXP - 1) < LONG_DOUBLE_MAX);
        assert(LONG_DOUBLE_MIN_EXP < DOUBLE_MIN_EXP
            || ldexp(1.0, LONG_DOUBLE_MIN_EXP - 1) == LONG_DOUBLE_MIN);
    #endif

    assert(LONG_DOUBLE_MIN <= 1e-37);
    assert(LONG_DOUBLE_MIN_10_EXP <= -37);
    puts("\033[32mSUCCESS testing <float.h>");
    return EXIT_SUCCESS;
}

