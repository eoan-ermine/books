int f(void) {
    _Bool b = 0;
    unsigned char* p = (unsigned char*)&b;

    *p = 10;
    // reeading from b is now UB
    return b == 0;
}

// May be compiled as

//  f:
//      movl $11, %eax
//      ret