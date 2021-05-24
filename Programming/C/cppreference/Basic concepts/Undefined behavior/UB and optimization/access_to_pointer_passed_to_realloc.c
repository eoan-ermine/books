#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = (int*)malloc(sizeof(int));
    int *q = (int*)realloc(p, sizeof(int));

    *p = 1; // UB access to pointer that was passed to realloc
    *q = 2;
    if(p == q) {
        printf("%d%d\n", *p, *q);
    }
}

// Possible output: 12
// Other possible output: 22