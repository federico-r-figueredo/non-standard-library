#include <assert.h>
#include <character-type.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void print_character_class(const char* function_name, int (*function)(int)) {
    // display a printable character class

    fputs(function_name, stdout);
    fputs(": ", stdout);
    for (int character = EOF; character <= UCHAR_MAX; ++character) {
        if ((*function)(character)) {
            fputc(character, stdout);
        }
    }

    fputs("\n", stdout);
}

int main(int argc, char** argv) {
    // test both macros and functions

    // display printable classes
    print_character_class("is_punctuation", &is_punctuation);
    print_character_class("is_digit", &is_digit);
    print_character_class("is_lowercase", &is_lowercase);
    print_character_class("is_upper_case", &is_upper_case);
    print_character_class("is_alphabetic", &is_alphabetic);
    print_character_class("is_alphanumeric", &is_alphanumeric);

    // test macros for required characters
    for (char* string = "0123456789"; *string; ++string) {
        assert(is_digit(*string) && is_hexadecimal(*string));
    }
    
    for (char* string = "abcdefABCDEF"; *string; ++string) {
        assert(is_hexadecimal(*string));
    }

    for (char* string = "abcdefghijklmnopqrstuvwxyz"; *string; ++string) {
        assert(is_lowercase(*string));
    }

    for (char* string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; *string; ++string) {
        assert(is_upper_case(*string));
    }

    for (char* string = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"; *string; ++string) {
        assert(is_punctuation(*string));
    }

    for (char* string = "\f\n\r\t\v"; *string; ++string) {
        assert(is_spacing(*string) && is_control(*string));
    }

    assert(is_spacing(' ') && is_printable(' '));
    assert(is_control('\a') && is_control('\b'));

    // test macros for all valid codes
    for (int character = EOF; character <= UCHAR_MAX; ++character) {
        // test for proper class membership    
        if (is_digit(character)) {
            assert(is_alphanumeric(character));
        }

        if (is_upper_case(character)) {
            assert(is_alphabetic(character));
        }

        if (is_lowercase(character)) {
            assert(is_alphabetic(character));
        }

        if (is_alphabetic(character)) {
            assert(is_alphabetic(character) && !is_digit(character));
        }

        if (is_alphanumeric(character)) {
            assert(is_graphical(character) && !is_punctuation(character));
        }

        if (is_punctuation(character)) {
            assert(is_graphical(character));
        }

        if (is_graphical(character)) {
            assert(is_printable(character));
        }

        if (is_spacing(character)) {
            assert(character == ' ' || !is_printable(character));
        }

        if (is_control(character)) {
            assert(!is_alphanumeric(character));
        }
    }

    // test functions for required characters
    for (char* string = "0123456789"; *string; ++string) {
        assert((is_digit)(*string) && (is_hexadecimal)(*string));
    }
    
    for (char* string = "abcdefABCDEF"; *string; ++string) {
        assert((is_hexadecimal)(*string));
    }

    for (char* string = "abcdefghijklmnopqrstuvwxyz"; *string; ++string) {
        assert((is_lowercase)(*string));
    }

    for (char* string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; *string; ++string) {
        assert((is_upper_case)(*string));
    }

    for (char* string = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"; *string; ++string) {
        assert((is_punctuation)(*string));
    }

    for (char* string = "\f\n\r\t\v"; *string; ++string) {
        assert((is_spacing)(*string) && (is_control)(*string));
    }

    assert((is_spacing)(' ') && (is_printable)(' '));
    assert((is_control)('\a') && (is_control)('\b'));

    // test functions for all valid codes
    for (int character = EOF; character <= UCHAR_MAX; ++character) {
        // test for proper class membership    
        if ((is_digit)(character)) {
            assert((is_alphanumeric)(character));
        }

        if ((is_upper_case)(character)) {
            assert((is_alphabetic)(character));
        }

        if ((is_lowercase)(character)) {
            assert((is_alphabetic)(character));
        }

        if ((is_alphabetic)(character)) {
            assert((is_alphabetic)(character) && !(is_digit)(character));
        }

        if ((is_alphanumeric)(character)) {
            assert((is_graphical)(character) && !(is_punctuation)(character));
        }

        if ((is_punctuation)(character)) {
            assert((is_graphical)(character));
        }

        if ((is_graphical)(character)) {
            assert((is_printable)(character));
        }

        if ((is_spacing)(character)) {
            assert(character == ' ' || !(is_printable)(character));
        }

        if ((is_control)(character)) {
            assert(!(is_alphanumeric)(character));
        }
    }

    puts("\033[32mSUCCESS testing <character-type.h>");

    return EXIT_SUCCESS;
}