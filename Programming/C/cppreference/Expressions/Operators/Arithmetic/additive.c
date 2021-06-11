/*
Form:
    1) lhs + rhs
    2) lhs - rhs
1) addition: lhs and rhs must be one of the following
    * both have arithmetic types
    * one is a pointer to complete obj, the other has integer type
2) subtraction: lhs and rhs must be one of the following
    * both have arithmetic types, including complex and imaginary
    * rhs has pointer to complete object type, rhs has integer type
    * both are pointers to complete obj of compatible types, ignoring qualifiers
*/

/*
    * If one operand is NaN, the result is NaN
    * Infinity minus infinity is NaN and FE_INVALID is raised
    * Infinity plus the negative infinity is NaN and FE_INVALID is raised
    
    Complex and imaginary addition and subtraction are defined as they defined,
    see cppreference for more info
*/

int main(void) {
    int n = 4, m = 3;
    int a[n][m];        // VLA of 4 VLAs of 3 ints each
    int (*p)[m] = a;    // p == &a[0]
    p = p + 1;          // p == &a[1]
    (*p)[2] = 99;       // changes a[1][2]
}