#include <unordered_set>

#include <iostream>
#include <string>

int main() {
	std::string line;
	std::getline(std::cin, line, '\n');

	std::unordered_set<char> chars;
	for(const char& x: line) {
		chars.insert(x);
	}
	std::cout << (chars.size() == line.size() ? "UNIQUE" : "NOT UNIQUE") << std::endl;

	// Complexity: O(n)
	// Without additional data structures:

	bool unique = true;
	std::sort(line.begin(), line.end());
	for(auto it = line.begin(), end = line.end() - 1; it != end; ++it) {
		if(*it == *(it + 1)) {
			unique = false;
			break;
		}
	}
	std::cout << (unique ? "UNIQUE" : "NOT UNIQUE") << std::endl;
}