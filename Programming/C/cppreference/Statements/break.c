#include <stdio.h>

int main(void) {
    int i = 2;
    switch(i) {
        case 1: printf("1");
        case 2: printf("2");
        case 3: printf("3");
        case 4:
        case 5: printf("45");
                break;
        case 6: printf("6");
    }
    printf("\n");

    for(int j = 0; j < 2; ++j) {
        for(int k = 0; k < 5; ++k) {
            printf("%d%d", j, k);
        }
    }
    printf("\n");
    for(int j = 0; j < 2; ++j) {
        for(int k = 0; k < 5; ++k) {
            if(k == 2) break;
            printf("%d%d", j, k);
        }
    }
}