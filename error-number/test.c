/* test error_number macro */
#include <assert.h>
#include <error-number.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // test basic working of error_number
    assert(error_number == 0);
    perror("No error reported as");

    error_number = ERROR_RANGE;
    assert(error_number == ERROR_RANGE);
    perror("Range error reported as");
    
    error_number = 0;
    assert(error_number == 0);


    //sqrt(-1.0);
    error_number = ERROR_DOM;
    assert(error_number == ERROR_DOM);
    perror("Domain error reported as");

    puts("\033[32mSUCCESS testing <errorr-number.h>");
    return EXIT_SUCCESS;
}