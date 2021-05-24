#include <stdio.h>

#define FUNCTION(name, a) int fun_##name(int x) { return (a)*x; }

FUNCTION(quadruple, 4)
FUNCTION(double, 2)

#undef FUNCTION
#define FUNCTION 34
#define OUTPUT(a) puts(#a)

#define print_err(format, args...) fprintf(stderr, format, ##args); // GNU EXTENSION
#define print(format, ...) printf(format, ##__VA_ARGS__); // GNU EXTENSION

int main(void) {
    printf("quadruple(13): %d\n", fun_quadruple(13));
    printf("double(21): %d\n", fun_double(21));
    printf("%d\n", FUNCTION);
    OUTPUT(million);
}