#include <stdio.h>

int main() {
    goto lab1; // OK: going into the scope of a regular variable
        int n = 5;
    lab1:; // Note, n is uninitialized, as if declared by int n;
    
    //   goto lab2;   // Error: going into the scope of two VM types
    {
            double a[n]; // a VLA
            int (*p)[n]; // a VM pointer
        lab2:
    }
    // If goto leaves the scope of a VLA, it's deallocated

    {
        int n = 1;
    label:;
        int a[n]; // re-allocated 10 times, each with a different size
        if (n++ < 10) goto label; // leaving the scope of a VM
    }

    // goto can be used to leave a multi-level loop easily
    for(int x = 0; x < 3; ++x) {
        for(int y = 0; y < 3; ++y) {
            printf("(%d;%d)\n", x, y);
            if(x + y >= 3) goto endloop;
        }
    }
    endloop:;
}