#include <iostream>

int b(int n) {
    if(n <= 2) {
        return n + 1;
    }    
    return b(n - 1) - 2 * b(n - 2) + 3 * b(n - 3);
}

int main() {
    int n; std::cin >> n;
    std::cout << b(n);
    return 0;
}