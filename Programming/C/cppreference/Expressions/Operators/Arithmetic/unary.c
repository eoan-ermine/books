#include <stdio.h>
#include <complex.h>
#include <limits.h>

/*
Form:
    + expression    (1)
    - expression    (2)
1) unary plus (promotion)
2) unary minus (negation)
where
    expression - expression of any arithmetic type
Both unary plus and unary minus first apply integral promotions to their operand, and then
    * unary plus returns the value after promotion
    * unary minus returns the negative of the value after promotion
Reutrn: the type after promotion, rvalue
*/

int main(void) {
    char c = 'a';
    printf("sizeof char: %zu sizeof int: %zu\n", sizeof c, sizeof +c);

    printf("-1, where 1 is signed: %d\n", -1);
    printf("-1, where 1 is unsigned: %u\n", -1u);

    // undefined behavior because the math value of -INT_MAX = INT_MAX + 1
    // (i.e. 1 more than the maximum possible value for signed int)
    // printf("%d\n", -INT_MIN);

    double complex z = 1 + 2*I;
    printf("-(1+2i) = %.1f%+.1f\n", creal(-z), cimag(-z));
}