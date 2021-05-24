#include <stdio.h>

int main() {
    // Except for bit fields, objects are composed
    // of contiguous sequences of one or more bytes,
    // each consisting of CHAR_BIT bits, and can be copied
    // with memcpy into an object of type unsigned char[n],
    // where n is the size of the object. The contents of the
    // resulting array are known as object representation. 

    unsigned char x[sizeof(int)];
    for(int i = 0; i < sizeof(int); ++i) {
        x[i] = i;
        printf("%d", i);
    }
    printf("\n");
    printf("%d\n", *(int*)(x));

    int number = 255;
    unsigned char* bytes = &number;

    for(int i = 0; i < 4; ++i) {
        printf("%d ", bytes[i]);
    }
    bytes[2] = 128;
    printf("\n%d", *(int*)(bytes));
}