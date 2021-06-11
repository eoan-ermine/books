#include <stdio.h>

int f(char c) { return c; }

int main(void) {
    int n = 1;
    
    int *p = &n; // address of object n
    int (*fp)(char) = &f; // address of function f

    int a[3] = {1, 2, 3};
    int *beg=a, *end=&a[2];
    
    printf("*end = %d", *end);
}

// &*expression - special case: & and * cancel each other, neither one is evaluated

// &expression[expression] - special case: & and the * that is implied
// in [] cancel each other, only the addition implied in [] is evaluated