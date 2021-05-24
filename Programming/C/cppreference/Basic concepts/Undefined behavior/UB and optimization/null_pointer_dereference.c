#include <stddef.h>

int foo(int* p) {
    int x = *p;
    if(!p) return x; // Either UB above or this branch is never taken
    else return 0;
}

int bar() {
    int* p = NULL;
    return *p; // Unconditional UB
}

// May be compiled as:

//  foo:
//      xorl %eax, %eax
//      ret
//  bar:
//      retq