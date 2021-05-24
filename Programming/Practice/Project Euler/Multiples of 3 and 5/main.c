#include <stdio.h>

int main() {
    int result = 0;
    for(int i = 1; i < 1000; ++i) result += (i % 3 == 0 || i % 5 == 0) ? i : 0;
    printf("%d", result);
}