#include <assert.h>

/*
Form:
    lhs < rhs   (1)
    lhs > rhs   (2)
    lhs <= rhs  (3)
    lhs >= rhs  (4)

1) less-than expression
2) greater-than expression
3) less or equal expression
4) greater or equal expression

where
    lhs, rhs - expression that both have real type
               or both have pointer to object type
Result: int (one or zero)
*/

int main(void) {
    assert(1 < 2);
    assert(2+2 <= 4.0); // int converts to double, two 4.0's compare equal

    struct { int x, y; } s;
    assert(&s.x < &s.y); // struct members compare in order of declaration

    double d = 0.0/0.0; // NaN
    assert( !(d < d) );
    assert( !(d > d) );
    assert( !(d >= d) );
    assert( !(d <= d) ); 

    float f = 0.1;  // f = 0.100000001490116119384765625
    double g = 0.1; // g = 0.1000000000000000055511151231257827021181583404541015625
    assert(f > g); // different values
}