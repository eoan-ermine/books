#include <stdio.h>

/*
    E1[E2] = *((E1) + (E2))
*/

int main(void) {
    int a[3] = {1, 2, 3};
    printf("%d %d\n",   a[2],   // n == 3
                        2[a]);  // same, n == 3
    a[2] = 7; // Subscripts are lvalues

    int n[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*p)[3] = &n[1]; // elements of n are arrays
    printf("%d %d %d\n", (*p)[0], p[0][1], p[0][2]); // access n[1][] via p
    int x = n[1][2]; // applying [] again to the array n[1]
    printf("%d\n", x);

    printf("%c %c\n", "abc"[2], 2["abc"]);
}