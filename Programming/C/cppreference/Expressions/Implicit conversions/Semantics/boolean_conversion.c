#include <stdbool.h>
#include <complex.h>

int main() {
    // The values that compare equal to zero are converted
    // to 0, all other values are converted to 1

    bool b1 = 0.5; // b1 = 1;
    bool b2 = 2.0*I; // b2 == 1
    bool b3 = 0.0 + 3.0*I; // b3 == 1
    bool b4 = 0.0/0.0; // b4 == 1
}