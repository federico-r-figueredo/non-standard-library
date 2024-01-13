/* is_control function */
#include "character-type.h"

int (is_control)(int character) {
    // test for control character
    return (_character_type[character] & (_BB | _CN));
}