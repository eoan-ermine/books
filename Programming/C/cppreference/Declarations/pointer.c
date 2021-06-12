#include <stdio.h>

void syntax() {
    // Form:
    // * (attr-spec-seq) (qualifiers) declarator

    // where

    // declarator may be the ident that names the
    // pointer being declared, including another
    // pointer declarator

    float *p, // p is a pointer to float
          *pp; // pp is a pointer to a pointer to float
    int (*fp)(int); // fp is a pointer to function with type int(int)

    // The qualifiers qualify the type of the pointer
    // that is being declared

    int n;
    const int *pc = &n; // pc is a non-const pointer
                        // to a const int
//  *pc = 2; // Error: n cannot be changed through pc without a cast
    pc = 0; // Ok: pc itself can be changed

    int * const cp = &n; // cp is a const pointer to a non-const int
    *cp = 2; // OK to change n through cp
//  cp = NULL; // Error: cp itself cannot be changed

    int * const * pcp = &cp; // non-const pointer to const pointer to non-const int

    // The attr-spec-seq is an optional list of attributes, applied to the declared pointer
}

void pointers_to_objects() {
    // Can be initialized with the result of
    // the address-of operator applied to an expr
    // of obj type

    int n;
    int *np = &n; // pointer to int
    int * const *npp = &np; // non-const pointer to const pointer to non-const int

    int a[2];
    int (*ap)[2] = &a; // pointer to array of int

    struct S {
        int n;
    } s = {1};
    int* sp = &s.n; // pointer to the int that is a member of s

    // Indirection operator (unary *) returns the lvalue
    // identifying the pointed-to object

    int *p = &n; // pointer p is pointing to n
    *p = 7; // stores 7 in n
    printf("%d\n", *p); // lvalue-to-rvalue conversion
                        // reads the value from n

    // Pointer to the first element of an array
    // can be initialized with an expression
    // of array type:

    int a[2];
    int *p = a; // pointer to a[0]

    int b[3][3];
    int (*row)[3] = b; // pointer to b[0]
}

int g(int n) {
    printf("%d\n", n);
    return n * n;
}
int c() {
    return 2;
}

void pointers_to_functions() {
    // Because of the function-to-pointer conversion,
    // the address-of operator is optional

    void f(int);
    void (*pf1)(int) = &f;
    void (*pf2)(int) = f; // same as f

    //  Pointer to func can be used on the
    // left-hand side of the function call operator
    // this invokes the pointer-to function:

    int (*p)(int) = g;
    int x = p(7);

    // Derefencing a function pointer yields
    // the function designator for the pointed-to function

    int (*d)() = c;
    (*d)(); // function f invoked through the function designator
    d(); // function f invoked directly through the pointer

    // Compatibility of function types ignores
    // top-level qualifiers of the func params

    int v(int), vc(const int);
    int(*pc)(const int) = v; // OK
    int(*pd)(int) = vc; // OK
    pc = pd; // OK
}

void pointers_to_void() {
    // Pointer to object of any type can be converted
    // to pointer to void and vice versa

    int n = 1, *p = &n;
    void* pv = p; // int* to void*
    int* p2 = pv; // void* to int*
    printf("%d\n", *p2); // prints 1
}

void notes() {
    // Dereferencing a pointer to the type
    // different from the declared type of the object
    // is almost always undefined behavior.
}