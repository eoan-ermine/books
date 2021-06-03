#include <iostream>
#include <algorithm>
#include <string>

int main() {
	std::string first, second; std::getline(std::cin, first);
	std::getline(std::cin, second);

	std::cout << (std::equal(first.begin(), first.end(), second.rbegin()) ? "YES" : "NO");
}
