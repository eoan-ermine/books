#include <stdio.h>
#include <complex.h>
#include <math.h>

/*
Form:
    1) lhs * rhs
    2) lhs / rhs
    3) lhs % rhs
1) multiplication. lhs and rhs must have arithmetic types
2) division. lhs and rhs must have arithmetic types
3) remainder. lhs and rhs must have integer types
*/

/*
    * If one operand is a NaN, the result is a NaN
    * Multiplication of infinity by zero gives NaN and FE_INVALID is raised
    * Multiplication of infinity by a nonzero gives infinity
*/

/*
    * Dividing a non-zero number by 0.0 gives the correctly-signed infinity and FE_DIVBYZERO is raised
    * Dividing 0.0 by 0.0 gives NaN and FE_INVALID is raised
*/

/*
    * The sign of the remainder is defined in such a way that if the quotient a/b is representable in the result type, then
      (a/b)*b + a%b == a
    * If the second operand is zero, the behavior is undefined
    * If the quotient a/b is not representable in the result type, the behavior of both a/b and a%b is undefined
*/

int main(void) { 
    double complex z = (1 + 0*I) * (INFINITY + I*INFINITY);
    // textbook formula would give
    // (1+i0)(∞+i∞) ⇒ (1×∞ – 0×∞) + i(0×∞+1×∞) ⇒ NaN + I*NaN
    // but C gives a complex infinity
    printf("%f + i*%f\n", creal(z), cimag(z));

    // textbook formula would give
    // cexp(∞+iNaN) ⇒ exp(∞)×(cis(NaN)) ⇒ NaN + I*NaN
    // but C gives  ±∞+i*nan
    double complex y = cexp(INFINITY + I*NAN);
    printf("%f + i*%f\n", creal(y), cimag(y));
}