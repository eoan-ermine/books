#include <iostream>

const int DOMINO_SQUARE = 2;

int main() {
	int m, n; std::cin >> m >> n;
	std::cout << (m * n) / DOMINO_SQUARE;
}
