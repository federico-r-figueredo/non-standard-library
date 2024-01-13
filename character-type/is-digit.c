/* is_digit function */
#include "character-type.h"

int (is_digit)(int character) {
    // test for digit
    return (_character_type[character] & _DI);
}