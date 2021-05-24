#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {SIZE = 8};
int main(void) {
    int array[SIZE], n = 0;
    
    while(n < SIZE) array[n++] = rand() % 2;
    puts("Array filled!");
    
    while(n < SIZE) printf("%d ", array[n++]);
    printf("\n");

    // classic strcpy() implementation
    char src[] = "Hello, world", dst[sizeof src], *p = dst, *q = src;
    while(*p++ = *q++) ; // Assignment return assigned value
    puts(dst);
}