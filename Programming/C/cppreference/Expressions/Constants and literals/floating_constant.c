#include <stdio.h>

int main() {
    double d = 0x1.2p3; // hex fraction 1.2 (decimal 1.125) scaled by 2^3, that is 9.0
    d = 1.2e3; // decimal fraction 1.2 scaled by 10^3, that is 1200.0
    
    // Suffix f or F = float
    // Suffix l or L - long

    d = 1e0; // floating-point 1.0

    d = 1.; // floating point 1.0
    d = .1; // floating-point 0.1

    printf("15.0 = %a\n", 15.0);
    printf("0x1.ep+3 = %f\n", 0x1.ep+3);

    // Constants outside the range of type double
    printf("+2.0e+308 --> %g\n", 2.0e+308);
    printf("+1.0e-324 --> %g\n", 1.0e-324);
    printf("-1.0e-324 --> %g\n", -1.0e-324);
    printf("-2.0e+308 --> %g\n", -2.0e+308);
}