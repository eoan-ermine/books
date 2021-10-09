#include <iostream>

int main() {
	int n, result = 0; std::cin >> n; std::cin.ignore();

	for(int c = std::cin.get();c != '\n';) {
		std::cout << c << std::endl;
		if(std::cin.peek() == c) {
			++result; std::cin.ignore(1);
		}
	}

	std::cout << result;
}
