// 1. If one operand is long double, long double complex, or
// long double imaginary, the other operand is implicitly
// converted as follows:
//  * integer or real floating type to long double
//  * complex type to long double complex
//  * imaginary type to long double imaginary

// 2. Otherwise, if one operand is double, double complex,
// or double imaginary, the other operand is implicitly
// converted as follows:
//  * integer or real floating type to double
//  * complex type to double complex
//  * imaginary type to double imaginary

// 3. Otherwise, if one operand is float, float complex, or
// float imaginary, the other operand is implicitly converted
// as follows:
//  * integer type to float
//  * complex type remains float complex
//  * imaginary type remains float imaginary

// 4. Otherwise, both operands are integers. Both operands
// undergo integer promotions; then, after integer promotion
// , on of the following cases applies:
//  * if the types are the same, that type is the common type
//      * if the types have the same signedness, the operand
//        whose type has the lesser conversion rank is
//        is implicitly converted to the other type
//  * else, the operands have different signedness:
//      * if the signed type can represent all values of
//        the unsigned type, then the operand with the
//        unsigned type is implicitly converted to the
//        signed type
//      * else, both operands undergo implicit conversion
//        to the unsigned type counterpart of the signed
//        operand's type

int main() {
    1.f + 20000001; // int is converted to float
    (char)'a' + 1L; // first, char 'a' is promoted to int
                    // different types: int and long
                    // same signedness: both signed
                    // different rank: long is of greater rank that int
                    // therefore, int 97 is converted to long 97
                    // the result is 97 + 1 = 98 of type signed long

    2u - 10;        // different types: unsigned int and signed int
                    // different signedness
                    // same rank
                    // therefore, signed int 10 is converted to unsigned int 10
                    // since the arithmetic operation is performed for unsigned integers
                    // the calculation performed is (2 - 10) module (2 raised to n), where n is the number of bits of unsigned int
                    // if unsigned int is 32-bit long, then
                    // the result is (-8) module (2 raised to 32) = 4294967288 of type unsigned int
    
    5UL - 2ULL;     // different types: unsigned long and unsigned long long
                    // same signedness
                    // different rank: rank of unsigned long long is greater
                    // therefore, unsigned long 5 is converted to unsigned long long 5
                    // since the arithmetic operation is performed for unsigned integers
                    // if unsigned long long is 64-bit long, then
                    // the result is (5 - 2) module (2 raised to 64) = 3 of type unsigned long long
    
    0UL - 1UL;      // different types: unsigned long and signed long long
                    // different signedness
                    // different rank: rank of signed long long is greater
                    // if ULONG_MAX > LLONG_MAX, then signed long long cannot represent all unsigned long
                    // therefore, this is the last case: both operands are converted to unsigned long long
                    // unsigned long 0 is converted to unsigned long long 0
                    // since the arithmetic operation is performed for unsigned integers
                    // if unsigned long long is 64-bit long, then
                    // the calculation is (0 - 1) modulo (2 raised to 64)
                    // thus, the result is 18446744073709551615 of type unsigned long long
    
    // If both types are complex, the result is complex
    // If both operands are imaginary, the result type is imaginary
    // If both operands are real, the result type is real
    // If the two floating-point operands have different type domains, the result type is complex

    double complex z = 1 + 2*I;
    double f = 0;
    z + f;  // z remains as-is, f is converted to double
            // result is double complex
}