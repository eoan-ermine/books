#include <stdio.h>

int main(void) {
    for(int i = 0; i < 10; ++i) {
        if(i != 5) continue;
        printf("%d ", i); // this statement is skiped each time i != 5
    }

    printf("\n");

    for(int j = 0; j < 2; ++j) {
        for(int k = 0; k < 5; ++k) {
            if(k == 3) continue;
            printf("%d%d", j, k); // this statement is skiped each time k == 3
        }
    }
}