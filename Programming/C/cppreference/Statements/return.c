#include <stdio.h>

void fa(int i) {
    if(i == 2) {
        return;
    }
    printf("fa(): %d\n", i);
}

int fb(int i) {
    if(i > 4) {
        return 4;
    }
    printf("fb(): %d\n", i);
    return 2;
}

int main(void) {
    fa(2);
    fa(1);
    int i = fb(5);
    i = fb(i);
    printf("main(): %d\n", i);
}