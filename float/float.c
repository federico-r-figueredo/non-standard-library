/* values used by <float.h> macros -- IEEE 754  version */
#include "float.h"

// macros
#define DFRAC (49 + _DOUBLE_OFFSET)
#define DMAXE ((1U << (15 - _DOUBLE_OFFSET)) -1)
#define FFRAC (17 + _FLOAT_OFFSET)
#define FMAXE ((1U << (15 - _FLOAT_OFFSET)) -1)
#define LFRAC (49 + _LONG_DOUBLE_OFFSET)
#define LMAXE 0x7fff
#define LOG2  0.30103
#if _D0 != 0 // low to high words
    #define DINIT(w0, wx) wx, wx, wx, w0
    #define FINIT(w0, wx) wx, w0
    #define LINIT(w0, w1, wx) wx, wx, wx,w1, w0
#else        // high to low words
    #define DINIT(w0, wx) w0, wx, wx, wx
    #define FINIT(w0, wx) w0, wx
    #define LINIT(w0, w1, wx) w0, w1, w1, wx, wx, wx
#endif

// static data
_DoubleValues _double = {
    (int) ((DFRAC - 1) * LOG2),                                 // DOUBLE_DIGIT
    (int) DFRAC,                                                // DOUBLE_MANTISA_DIGIT
    (int) ((DMAXE - _DOUBLE_BIAS - 1) * LOG2),                  // DOUBLE_MAX_10_EXP
    (int) (DMAXE - _DOUBLE_BIAS - 1),                           // DOUBLE_MAX_EXP
    (int) (- _DOUBLE_BIAS * LOG2),                              // DOUBLE_MIN_10_EXP
    (int) (1 - _DOUBLE_BIAS),                                   // DOUBLE_MIN_EXP
    {DINIT((_DOUBLE_BIAS - DFRAC + 2)<<_DOUBLE_OFFSET, 0)},     // DOUBLE_EPSILON
    {DINIT((DMAXE << _DOUBLE_OFFSET) -1, ~0)},                  // DOUBLE_MAX
    {DINIT(1 << _DOUBLE_OFFSET, 0)}                             // DOUBLE_MIN
};

_DoubleValues _float = {
    (int) ((FFRAC - 1) * LOG2),                                 // FLOAT_DIGIT
    (int) FFRAC,                                                // FLOAT_MANTISA_DIGIT
    (int) ((FMAXE - _FLOAT_BIAS - 1) * LOG2),                   // FLOAT_MAX_10_EXP
    (int) (FMAXE - _FLOAT_BIAS - 1),                            // FLOAT_MAX_EXP
    (int) (- _FLOAT_BIAS * LOG2),                               // FLOAT_MIN_10_EXP
    (int) (1 - _FLOAT_BIAS),                                    // FLOAT_MIN_EXP
    {FINIT(_FLOAT_BIAS - FFRAC + 2 << _FLOAT_OFFSET, 0)},       // FLOAT_EPSILON
    {FINIT((FMAXE << _FLOAT_OFFSET) -1, ~0)},                   // FLOAT_MAX
    {FINIT(1 << _FLOAT_OFFSET, 0)}                              // FLOAT_MIN
};

#if _DOUBLE_LONG
_DoubleValues _long_double = {
    (int) ((LFRAC - 1) * LOG2),                                 // LONG_DOUBLE_DIGIT
    (int) LFRAC,                                                // LONG_DOUBLE_MANTISA_DIGIT
    (int) ((LMAXE - _LONG_DOUBLE_BIAS - 1) * LOG2),             // LONG_DOUBLE_MAX_10_EXP
    (int) (LMAXE - _LONG_DOUBLE_BIAS - 1),                      // LONG_DOUBLE_MAX_EXP
    (int) (- _LONG_DOUBLE_BIAS * LOG2),                         // LONG_DOUBLE_MIN_10_EXP
    (int) (1 - _LONG_DOUBLE_BIAS),                              // LONG_DOUBLE_MIN_EXP
    {LINIT(_LONG_DOUBLE_BIAS - LFRAC + 2, 0X8000, 0)},          // LONG_DOUBLE_EPSILON
    {LINIT(LMAXE - 1, ~0, ~0)},                                 // LONG_DOUBLE_MAX
    {LINIT(1, 0X8000, 0)}                                       // LONG_DOUBLE_MIN
};
#else
_DoubleValues _long_double = {
    (int) (DFRAC * LOG2),                                       // LONG_DOUBLE_DIGIT
    (int) DFRAC,                                                // LONG_DOUBLE_MANTISA_DIGIT
    (int) ((DMAXE - _LONG_DOUBLE_BIAS - 1) * LOG2),                  // LONG_DOUBLE_MAX_10_EXP
    (int) (DMAXE - _LONG_DOUBLE_BIAS - 1),                           // LONG_DOUBLE_MAX_EXP
    (int) (- _LONG_DOUBLE_BIAS * LOG2),                              // LONG_DOUBLE_MIN_10_EXP
    (int) (1 - _LONG_DOUBLE_BIAS),                                   // LONG_DOUBLE_MIN_EXP
    {DINIT(_LONG_DOUBLE_BIAS = DFRAC + 2 << _DOUBLE_OFFSET, 0)},     // LONG_DOUBLE_EPSILON
    {DINIT((DMAXE << _DOUBLE_OFFSET) - 1, ~0)},                 // LONG_DOUBLE_MAX
    {DINIT(1 << _DOUBLE_OFFSET, 0)},                            // LONG_DOUBLE_MIN
}

#endif