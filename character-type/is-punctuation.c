/* is_punctuation function */
#include "character-type.h"

int (is_punctuation)(int character) {
    return (_character_type[character] & _PU);
}