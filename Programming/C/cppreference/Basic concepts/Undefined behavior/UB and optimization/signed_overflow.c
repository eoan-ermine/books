int foo(int x) {
    return x + 1 > x; // either true or UB due to signed overflow
}

// may be compiled as

//  foo:
//      movl $1, %eax
//      ret