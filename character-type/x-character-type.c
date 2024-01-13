/* _characterType conversion table -- ASCII version */
#include "character-type.h"
#include <limits.h>
#include <stdio.h>
#if EOF != -1 || UCHAR_MAX != 255
#error WRONG CHARACTERTYPE TABLE
#endif

// macros
#define XDI (_DI | _XD)
#define XLO (_LO | _XD)
#define XUP (_UP | _XD)

// static data
static const short character_type_table[257] = { 0, // EOF
    _BB, _BB, _BB, _BB, _BB, _BB, _BB, _BB,
    _BB, _CN, _CN, _CN, _CN, _CN, _BB, _BB,
    _BB, _BB, _BB, _BB, _BB, _BB, _BB, _BB,
    _BB, _BB, _BB, _BB, _BB, _BB, _BB, _BB,
    _SP, _PU, _PU, _PU, _PU, _PU, _PU, _PU,
    _PU, _PU, _PU, _PU, _PU, _PU, _PU, _PU,
    XDI, XDI, XDI, XDI, XDI, XDI, XDI, XDI,
    XDI, XDI, _PU, _PU, _PU, _PU, _PU, _PU,
    _PU, XUP, XUP, XUP, XUP, XUP, XUP, _UP,
    _UP, _UP, _UP, _UP, _UP, _UP, _UP, _UP,
    _UP, _UP, _UP, _UP, _UP, _UP, _UP, _UP,
    _UP, _UP, _UP, _PU, _PU, _PU, _PU, _PU,
    _PU, XLO, XLO, XLO, XLO, XLO, XLO, XLO,
    _LO, _LO, _LO, _LO, _LO, _LO, _LO, _LO,
    _LO, _LO, _LO, _LO, _LO, _LO, _LO, _LO,
    _LO, _LO, _LO, _PU, _PU, _PU, _PU, _BB      // rest all match nothing
};

const short *_character_type = &character_type_table[1];