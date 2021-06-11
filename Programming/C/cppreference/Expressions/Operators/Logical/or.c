#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
Form: lhs || rhs
where
    lhs - an expression of any scalar type
    rhs - an expression of any scalar type, which is only evaluated if lhs compares equal to 0
Result: int (zero or one)
*/

int main(void) {
    bool b = 2+2==4 || 2+2==5; // true
    printf("true or false = %s\n", b ? "true" : "false");

    // logical OR can be used simialar to perl's "or die", as long as rhs has scalar type
    fopen("test.txt", "r") || printf("could not open test.txt: %s\n", strerror(errno));
}