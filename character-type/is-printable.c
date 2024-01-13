/* is_printable function */
#include "character-type.h"

int (is_printable)(int character) {
    // test for printable character
    return (_character_type[character] & (_LO | _UP | _XA | _DI | _PU | _SP));
}
