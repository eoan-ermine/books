#include <iostream>

int main() {
	int n; std::cin >> n;

	std::string instruction;
	std::cin.ignore();

	int x = 0;

	for(int i = 0; i < n; ++i) {
		std::getline(std::cin, instruction);
		for(const char& c: instruction) {
			if(c == '-') { --x; break; }
			else if(c == '+') { ++x; break; }
		}
	}

	std::cout << x;
}
