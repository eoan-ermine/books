#include <stdint.h>

int main() {
    // Conversion of a value of any type to any compatible type is no-op
    uint8_t (*a)[10]; // if uint8_t is a typedef to unsigned char
    unsigned char (*b)[] = a; // then these pointer types are compatible
}