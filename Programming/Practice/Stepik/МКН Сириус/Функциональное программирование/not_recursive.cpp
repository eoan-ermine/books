#include <iostream>

int b(int n, int a = 1,) {
    if(n <= 2) {
        return n + 1;
    }

    int a = 1;
    int b = 2;
    int c = 3;

    int result = 0;

    for(int i = 2; i < n; ++i) {
        result = c - 2 * b + 3 * a;

        a = b;
        b = c;
        c = result;
    }

    return result;
}

int main() {
    int n; std::cin >> n;
    std::cout << b(n);
    return 0;
}