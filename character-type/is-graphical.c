/* is_graphical function */
#include "character-type.h"

int (is_graphical)(int character) {
    // test for graphical character
    return (_character_type[character] & (_LO | _UP | _XA | _DI | _PU));
}