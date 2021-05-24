#include <stdio.h>

void f(int n) { // scope of the func param 'n' begins
    ++n; // 'n' is in scope and refers to the function param
    // int n = 2; // error: cannot redeclare ident in the same scope
    for(int n = 0; n < 10; ++n) { // scope of loop-local 'n' begins
        printf("%d\n", n); // prints 0 1 2 3 4 5 6 7 8 9
    } // scope of the loop-local 'n' ends
    // the func param 'n' is back in scope
    printf("%d\n", n); // prints the value of the param + 1
} // scope of function parameter 'n' ends

// int a = n;
// ^ Error: name 'n' is not in scope

int main() {
    f(5);
}