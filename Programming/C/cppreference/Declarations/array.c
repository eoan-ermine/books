#include <stddef.h>
#include <stdio.h>

void syntax() {
    // Form:
    
    // 1) [static(opt) qualifiers(opt) expression(opt)] attr-spec-seq(opt)
    // 2) [qualifiers(opt) static(opt) expression(opt)] attr-spec-seq(opt)
    // 3) [qualifiers(opt)*] attr-spec-seq(opt)

    // 1,2 - general array declarator syntax
    // 3 - declarator for VLA of unspec size

    // expression - any expr other than comma operator, designates the number of elements in the array
    // qualifiers - any combination of const, restrict of volatile qualifiers, only allowed
    //              in function parameter list; qualifies the pointer type to which
    //              this array parameter is transformed
    // attr-spec-seq - optional list of attributes

    float fa[1],    // fa is an array of 11 floats
          *afp[17]; // afp is an array of 17 pointers to floats
}

void arrays_of_constant_known_size() {
    int n[10]; // integer consts are const exprs
    char o[sizeof(double)]; // sizeof is a const expr
    enum {
        MAX_SZ = 100
    };
    int n[MAX_SZ]; // enum consts are const exprs

    int a[5] = {1, 2, 3}; // declares int[5] init to 1,2,3,0,0
    char str[] = "abc"; // declares char[4] init to 'a','b','c','\0'
}

// In each func call to a func where an array param
// uses the keyword static between brackets, the value
// of the actual parameter must be a valid pointer to the
// first element of an array with at least as many
// elements as specified by expression

void fadd(double a[static 10], const double b[static 10])
{
    for(int i = 0; i < 10; ++i) {
        if (a[i] < 0.0) return;
        a[i] += b[i];
    }
}

// a call to fadd may perform compile-time bounds checking
// and also permits optimizations such as prefetching 10 double

int execute(void) {
    double a[10] = {0}, b[20] = {0};
    fadd(a, b); // OK
    double x[5] = {0};
    fadd(x, b); // UB: array arg is too small
}

int f(const int a[20]) {
    // in this function, a has type const int*
    // (pointer to const int)
}

int g(const int a[const 20]) {
    // in this function, a has type const int* const
    // (const pointer to const int)
}

void variable_length_arrays() {
    // If expr is not an int const expr

    {
        int n = 1;
    label:
        int a[n];
        printf("The array has %zu elements\n", sizeof a / sizeof *a);
        if(n++ < 10) goto label; // leaving the scope of a VLA ends its lifetime
    }
}

// If the size is *, the decl is for a VLA of unspec size
// Such decl may only appear in a function prototype scope
// and delcared an array of a complete types

void foo(size_t x, int a[*]);
void foo(size_t x, int a[x]) {
    printf("%zu\n", sizeof a); // same as sizeof(int*)
}