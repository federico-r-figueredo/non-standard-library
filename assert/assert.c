/* _assert function */
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>

// print assertion message and abort
void _assert(const char * message) {
    fputs(message, stderr);
    fputs(" <-- assertion failed\n", stderr);
    abort();
}