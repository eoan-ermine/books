#include <stdio.h>
#include <inttypes.h>

int main() {
    // The following variables are initialized to the same value:
    int d = 42; // Decimal constant
    int o = 052; // Octal constant
    int x = 0x2a; // Hex constant
    int X = 0X2A; // Same hex constant
    int b = 0b101010; // Binary constant, C23

    // Integer suffixes:
    unsigned int ui = 42u;
    unsigned long int uli = 42ul;
    unsigned long long int ulli = 32ull;
    // u and l can be in uppercase/lowercase

    // There are no negative integer constants. -1 apply the unary
    // minus operator to the value represented
    // by the constant

    // All signed integer type in #if and #elif = intmax_t
    // Unsigned = uintmax_t

    // int z = 0xE+2 - Error
    int y = 0xa+2;
    int w = 0xE +2; // OK
    int c = (0xE)+2; // OK

    printf("123 = %d\n", 123);
    printf("0123 = %d\n", 0123);
    printf("0x123 = %d", 0x123);
    printf("12345678901234567890ull = %ull\n", 12345678901234567890ull);
    printf("12345678901234567890u = %"PRIu64"\n", 12345678901234567890u);
    printf("%llu\n", -9223372036854775808ull);

    // printf("%lld\n", 0922372036854775808); // ERROR
    // This value cannot fit in signed long long, which is the
    // biggest type allowed for unsuffixed decimal integer constant

    printf("%lld\n", -9223372036854775807ull - 1);
    // correct way to form signed value -9223372036854775808
}