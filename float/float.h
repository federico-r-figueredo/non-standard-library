/* float.h standard header j-- IEEE 754 version */
#ifndef _FLOAT
#define _FLOAT

#ifndef _VALUES
#include <x-values.h>
#endif

// type definitions

typedef struct {
    int _double_digit, _double_mantisa_digit, _double_max_10_exp, _double_max_exp, _double_min_10_exp, _double_min_exp;
    union {
        unsigned short _unsigned_short[5];
        float _float;
        double _double;
        long double _long_double;
    } _double_epsilon, _double_max, _double_min;
    
} _DoubleValues;

// declarations
extern _DoubleValues _double, _float, _long_double;

// double properties
#define DOUBLE_DIGIT _double._double_digit
#define DOUBLE_EPSILON _double._double_epsilon._double
#define DOUBLE_MANTISA_DIGIT _double._double_mantisa_digit
#define DOUBLE_MAX _double._double_max._double
#define DOUBLE_MIN _double._double_min._double
#define DOUBLE_MAX_10_EXP _double._double_max_10_exp
#define DOUBLE_MIN_10_EXP _double._double_min_10_exp
#define DOUBLE_MAX_EXP _double._double_max_exp
#define DOUBLE_MIN_EXP _double._double_min_exp

// float properties
#define FLOAT_DIGIT _float._double_digit
#define FLOAT_EPSILON _float._double_epsilon._float
#define FLOAT_MANTISA_DIGIT _float._double_mantisa_digit
#define FLOAT_MAX _float._double_max._float
#define FLOAT_MIN _float._double_min._float
#define FLOAT_MAX_10_EXP _float._double_max_10_exp
#define FLOAT_MIN_10_EXP _float._double_min_10_exp
#define FLOAT_MAX_EXP _float._double_max_exp
#define FLOAT_MIN_EXP _float._double_min_exp

// common properties
#define FLOAT_RADIX 2
#define FLOAT_ROUNDS _FLOAT_ROUNDS

// long double properties
#define LONG_DOUBLE_DIGIT _long_double._double_digit
#define LONG_DOUBLE_EPSILON _long_double._double_epsilon._long_double
#define LONG_DOUBLE_MANTISA_DIGIT _long_double._double_mantisa_digit
#define LONG_DOUBLE_MAX _long_double._double_max._long_double
#define LONG_DOUBLE_MIN _long_double._double_min._long_double
#define LONG_DOUBLE_MAX_10_EXP _long_double._double_max_10_exp
#define LONG_DOUBLE_MIN_10_EXP _long_double._double_min_10_exp
#define LONG_DOUBLE_MAX_EXP _long_double._double_max_exp
#define LONG_DOUBLE_MIN_EXP _long_double._double_min_exp

#endif