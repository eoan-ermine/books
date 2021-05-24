#include <stdio.h>
#include <stdlib.h>

enum {SIZE = 8};

int main(void) {
    int array[SIZE];
    for(size_t i = 0; i < SIZE; ++i) {
        array[i] = rand() % 2;
    }
    printf("Array filled!\n");
    for(size_t i = 0; i < SIZE; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    for(int i = 0; i < 1; ++i) {
        long i = 1; // valid C, invalid C++
                    // loop-statement establishes its own block scope
    }

    for(int n = 0; n < 10; ++n, printf("%d\n", n)) ; // null-statement

    for(;;) {
        printf("endless loop!");
    }
}