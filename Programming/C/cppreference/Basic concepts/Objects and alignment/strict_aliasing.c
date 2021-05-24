void main() {
    int i = 7;
    char* pc = (char*)(&i);

    if(pc[0] == '\x7') { // aliasing through char is ok
        puts("This system is little-endian");
    } else {
        puts("This system is big-endian");
    }

    float* pf = (float*)(&i);
    float d = *pf;  // UB: float lvalue *p cannot be used to access int
}

// int* and double* cannot alias
void f1(int *pi, double *pd, double d) {
    // the read from *pi can be done only once, before the loop
    for(int i = 0; i < *pi; ++i) *pd++ = d;
}

struct S { int a, b; };
// int* struct S* may alias because S in an aggregate type with a member of type int
void f2(int *pi, struct S *ps, struct S s) {
    // read from *pi must take place after every write through *ps
    for(int i = 0; i < *pi; ++i) *ps++ = s;
}