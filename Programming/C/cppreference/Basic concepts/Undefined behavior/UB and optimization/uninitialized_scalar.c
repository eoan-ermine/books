#include <stddef.h>

int main() {
    _Bool p;
    if(p) {
        puts("p is true");
    } else {
        puts("p is false");
    }
}

// May produce the following output:
// p is true
// p is false

size_t f(int x) {
    size_t a;
    if(x) {
        a = 42;
    }
    return a;
}

// May be compiled as

//  f:
//      mov eax, 42
//      ret