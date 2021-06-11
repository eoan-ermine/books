#include <stdbool.h>

void f(void) {
    #pragma STDC FENV_ACCESS ON

    static float v = 1.1e75;

    float u[] = { 1.1e75 }; // raises FE_INEXACT
    float w = 1.1e75;       // raises FE_INEXACT

    double x = 1.1e75;  // may raise FE_INEXACT
    float y = 1.1e75f; // may raise FE_INEXACT

    long double z = 1.1e75; // does not raise exceptions 
}

int main(void) {
    bool b = true;
    const double d = 3.14;
    int k = 3.15; // conversion from double to int
    int n = {12}, // optional braces
        *p = &n,  // non-constant expression OK for automatic variable
        (*fp)(void) = main;
    enum {RED, BLUE} e = RED; // enumerations are scalar types as well
}