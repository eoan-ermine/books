#include <stdio.h>

/*
C-style comments can contain
multiple lines.
*/

/* Or, just one line. */

// C++ style comments can comment one line.

// Or, they can
// be strung together.

int main(void) {
    // The below code won't be run
    // puts("Hello")

    // The bellow code will be run
    puts("World");

    int a, b, c, d;
    
    a = b //*divisor:*/ c
    + d; /* C89 compiles a = b / c + d;
            C99 compiles a = b + d; */
    
    // Other mechanism used for source code
    // exclusion are:

    #if 0
        puts("this will not be compiled");
        /* no conflict with C-style comments */
        // no conflict with C++-style comments
    #endif

    // and

    if(0) {
        puts("this will be compiled but not be executed");
    }
}