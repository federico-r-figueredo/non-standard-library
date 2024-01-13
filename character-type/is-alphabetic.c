/* is_alphabetic function */
#include "character-type.h"

int (is_alphabetic)(int character) {
    // test for alphabetic character
    return (_character_type[character] & (_LO | _UP | _XA));
}