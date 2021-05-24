#include <stdio.h>

enum {a, b};
int different(void) {
    if (sizeof(enum{b, a}) != sizeof(int)) {
        return a;
    }
    return b;
}

int main() {
    int i = 1, j = 2;
    if(i > 1)
        if(j > 2)
            printf("%d > 1 and %d > 2\n", i, j);
        else // this else is part of if(j > 2)
            printf("%d > 1 and %d <= 2\n", i, j);
    

    i = 2;
    if(i > 2) {
        printf("first is true\n");
    } else {
        printf("first is false\n");
    }

    i = 3;
    if(i == 3) printf("i == 3\n");
    if(i != 3) printf("i != 3 is true");
    else printf("i != 3 is false\n");
}