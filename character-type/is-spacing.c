/* is_spacing function */
#include "character-type.h"

int (is_spacing)(int character) {
    // test for spacing character
    return (_character_type[character] & (_CN | _SP | _XS));
}