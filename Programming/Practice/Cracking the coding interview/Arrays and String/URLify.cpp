#include <string>
#include <iostream>

void urlify(std::string& str) {
	std::size_t begin = 0;
	for(auto it = str.find(' ', begin); it != std::string::npos; begin = it + 1, it = str.find(' ', begin)) {
		str[it] = '%';
		str.insert(it + 1, "20");
	}
}

int main() {
	std::string line;
	std::getline(std::cin, line);

	urlify(line);
	std::cout << line << std::endl;
}