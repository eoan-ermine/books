#include <stdio.h>

void swap(int* a, int* b) {
    int j = *b;
    *b = *a;
    *a = j;
}

void insertion_sort(int s[], int n) {
    for(int i = 1; i < n; ++i) {
        for(int j = i; (j > 0) && (s[j] < s[j - 1]); --j) {
            swap(&s[j], &s[j - 1]);
        }
    }
}

int main() {
    int array[] = {3, 2, 1, 4, 5};
    insertion_sort(array, 5);

    for(int i = 0; i < 5; ++i) {
        printf("%d ", array[i]);
    }
}