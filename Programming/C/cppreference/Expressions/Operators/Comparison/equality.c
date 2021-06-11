#include <assert.h>

/*
Form:
    lhs == rhs (1)
    lhs != rhs
1) equal-to expression
2) not equal to expression
where
    lhs, rhs - expressions that
        * both have any arithmetic types
        * both are pointers to objects or function of
          compatible types, ignoring qualifiers of the pointed-to types
        * one is a pointer to object and the other is a pointer to void
        * one is a pointer to object or function and the other is a null
          pointer constant such as NULL
Result: int (zero or one)
*/

int main(void) {
    assert(2+2 == 4.0); // int converts to double, two 4.0's compare equal

    int n[2][3] = {1,2,3,4,5,6};
    int* p1 = &n[0][2]; // last element in the first row
    int* p2 = &n[1][0]; // start of second row
    assert(p1+1 == p2); // compare equal

    double d = 0.0/0.0; // NaN
    assert(d != d); // NaN does not equal itself

    float f = 0.1; // f = 0.100000001490116119384765625
    double g = 0.1; // g = 0.1000000000000000055511151231257827021181583404541015625
    assert(f != g); // different values
}