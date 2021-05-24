#include <stdio.h>
#include <stdlib.h>

enum {SIZE = 8};
int main(void) {
    int array[SIZE], n = 0;

    do array[n++] = rand() % 2;
    while(n < SIZE);
    puts("Array filled!");
    n = 0;

    do {
        printf("%d ", array[n]);
        ++n;
    } while(n < SIZE);
    printf("\n");

    int num = 1234, i = 0;
    char s[10];

    do s[i++] = num % 10 + '0';
    while((num /= 10) > 0);
    s[i] = '\0';
    puts(s);
}