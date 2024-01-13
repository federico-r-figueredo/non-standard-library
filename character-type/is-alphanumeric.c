/* is_alphanumeric function */
#include "character-type.h"

int (is_alphanumeric)(int character) {
    // test for alphanumeric character
    return (_character_type[character] & (_LO | _UP | _XA | _DI));
}