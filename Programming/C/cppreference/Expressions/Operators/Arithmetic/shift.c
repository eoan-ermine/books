#include <stdio.h>

/*
Form:
    1) lhs << rhs
    2) lhs >> rhs
1) left shift of lhs by rhs bits
2) right shift of lhs by rhs bits
where
    lhs, rhs - expressions of integer type
*/

/*
    First, integer promotions are performed on each operand
    The type of the result is the type of lhs after promotion

    The behavior is undefined if rhs is negative or is greater or equal the number of bits in the promoted lhs
*/

enum {ONE = 1, TWO = 2};
int main(void) {
    char c = 0x10;
    unsigned long long ulong_num = 0x123;
    printf("0x123 << 1 = %#llx\n"
           "0x123 << 63 = %#llx\n"  // overflow truncates high bits for unsigned numbers
           "0x10 << 10 = %#x\n",    // char is promoted to int
           ulong_num << 1, ulong_num << 63, c << 10);
    long long long_num = -1000;
    printf("-1000 >> 1 = %lld\n", long_num >> ONE); // implementation defined
}