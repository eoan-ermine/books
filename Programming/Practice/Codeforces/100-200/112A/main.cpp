#include <iostream>
#include <cctype>

namespace my {
	int tolower(char ch) {
		return std::tolower(static_cast<unsigned char>(ch));
	}
}

int main() {
	std::string lhs, rhs;
	std::getline(std::cin, lhs); std::getline(std::cin, rhs);

	int result = 0;
	for(int i = 0; i < lhs.size(); ++i) {
		int x = my::tolower(lhs[i]), y = my::tolower(rhs[i]);
		if(x < y) { result = -1; break; }
		else if(y < x) { result = 1; break; }
	}
	std::cout << result;
}
