/* is_lowercase function */
#include "character-type.h"

int (is_lowercase)(int character) {
    // test for lowercase character
    return (_character_type[character] & _LO);
}