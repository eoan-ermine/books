#include <iostream>
#include <cmath>

int main() {
	int element; int result;
	for(int n = 0; n < 5; ++n) {
		for(int m = 0; m < 5; ++m) {
			std::cin >> element;
			if(element == 1) {
				result = std::abs(n - 2) + std::abs(m - 2);
			}
		}
	}
	std::cout << result;
}
