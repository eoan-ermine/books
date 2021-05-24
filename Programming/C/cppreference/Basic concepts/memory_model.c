// The data storage (memory) available to a C program is one
// or more contiguous sequences of bytes. Each byte in memory
// has a unique address. 

// Byte is the smallest addressable unit of memory. 8 bytes+
// The types char, unsigned char, and signed char use one byte for both storage and value representation
// Number of bits in byte = CHAR_BIT

// Memory location is
//  * an object of scalar type
//  * or the largest contiguous sequence of bit fields of non-zero length

struct S {
    char a; // memory location #1
    int b: 5; // memory location #2
    int c: 11, // memory location #2 (continued)
         : 0,
        d : 8; // memory location #3
    struct {
        int ee: 8; // memory location #4
    } e;
};