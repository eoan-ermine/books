// Translation Unit 1
#include <stdio.h>
struct s {int i;}; // compatible with TU3's s, but not TU2's
extern struct s x = {0}; // compatible with TU3's x
extern void f(void); // compatible with TU2's f
int main()
{
   f();
   return x.i;
}
// Translation Unit 2
struct s {float f;}; // compatible with TU4's s, but not TU1's s
extern struct s y = {3.14}; // compatible with TU4's y
void f() // compatible with TU1's f
{
   return;
}
// Translation Unit 3
struct s {int i;}; // compatible with TU1's s, but not TU2's s
extern struct s x; // compatible with TU1's x
// Translation Unit 4
struct s {float f;}; // compatible with TU2's s, but not TU1's s
extern struct s y; // compatible with TU2's y
 
// the behavior is well-defined: only multiple declarations
// of objects and functions must have compatible types, not the types themselves

//Note: C++ has no concept of compatible
// types. A C program that declares two
// types that are compatible but not
// identical in different translation units
// is not a valid C++ program.