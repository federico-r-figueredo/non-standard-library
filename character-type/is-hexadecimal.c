/* is_hexadecimal function */
#include "character-type.h"

int (is_hexadecimal)(int character) {
    // test for hexadecimal
    return (_character_type[character] & _XD);
}