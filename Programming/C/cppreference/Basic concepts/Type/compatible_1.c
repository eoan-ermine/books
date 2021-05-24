// TU 1
struct S { int a; };
extern struct S *x; // compatible with TU2's x, but not with TU3's x
// TU 2
struct S;
extern struct S *x; // compatible with both x's
// TU 3
struct S { float a; };
extern struct S *x; // compatible with TU2's x, but not with TU1's x

// UB