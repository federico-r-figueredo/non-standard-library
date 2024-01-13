#define NDEBUG
#include "assert.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

// static data
static int value = 0;

// handle SIGABRT
static void field_abort(int signal_number) {

    if (value == 1) {   // expected result
        puts("SUCCESS testing <assert.h>");
        exit(EXIT_SUCCESS);
    } else {            // unexpected result
        puts("FAILURE testing <assert.h>");
        exit(EXIT_FAILURE);
    }
}

// test dummy assert macro
static void dummy() {
    int i = 0;
    assert(i == 0);
    assert(i == 1);
}

#undef NDEBUG
#include <assert.h>

// test both dummy and working forms
int main() {
    assert(signal(SIGABRT, &field_abort) != SIG_ERR);
    dummy();
    assert(value == 0); // should not abort
    ++value;
    fputs("Sample assertion failure message:\n", stderr);
    assert(value == 0);
    puts("FAILURE testing <assert.h>"); // should abort
    
    return EXIT_FAILURE;
}

                         