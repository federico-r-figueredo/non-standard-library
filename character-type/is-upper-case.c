/* is_upper_case function */
#include "character-type.h"

int (is_upper_case)(int character) {
    // test for uppercase character
    return (_character_type[character] & _UP);
}