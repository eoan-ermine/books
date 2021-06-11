#include <stdio.h>
#include <stdint.h>

/*
Form:
    1) ~ rhs
    2) lhs & rhs
    3) lhs | rhs
    4) lhs ^ rhs
1) bitwise NOT
2) bitwise AND
3) bitwise OR
4) bitwise XOR
where
    lhs, rhs - expressions of integer type
*/

int main(void) {
    uint16_t mask = 0x00f0;
    uint32_t a = 0x12345678;
    printf("Value: %#x mask: %#x\n"
           "Setting bits: %#x\n"
           "Clearing bits: %#x\n"
           "Selecting bits: %#x\n",
           a,mask,(a|mask),(a&~mask),(a&mask));
}