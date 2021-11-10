#include <iostream>
#include <string>

std::string compress(const std::string& original) {
	std::string result{};

	char previous = original[0];
	int count = 0;

	for(const char& x: original) {
		if(x == previous) {
			++count;
		} else {
			result.push_back(previous);
			result.append(std::to_string(count));
			count = 1;
		}
		previous = x;
	}
	result.push_back(previous);
	result.append(std::to_string(count));

	return (result.size() < original.size() ? result : original);
}

int main() {
	std::string line;
	std::getline(std::cin, line);

	std::cout << compress(line) << std::endl;
}