#include <stdbool.h>

// When the call is made to

// * a function without a prototype
// * a variadic function, where the argument expression is one
// of the trailing arguments that are matched against
// the ellipsis parameter

// Each argument of integer type undergoes integer promotion
// and each argument of type float is implicitly converted
// to the type double

int add_nums(int count, ...);

int main() {
    int sum = add_nums(2, 'c', true);
}