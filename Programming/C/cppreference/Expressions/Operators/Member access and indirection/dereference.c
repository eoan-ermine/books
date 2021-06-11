#include <stdio.h>

int main(void) {
    int n = 1;
    int* p = &n;
    
    printf("*p = %d\n", *p); // the value of *p is what's stored in n
    
    *p = 7; // *p is an lvalue

    printf("*p = %d\n", *p);
}