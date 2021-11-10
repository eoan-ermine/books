#include <string>
#include <unordered_map>
#include <iostream>

#include <cstddef>

int main() {
	std::string first, second;

	std::getline(std::cin, first);
	std::getline(std::cin, second);

	std::unordered_map<char, std::size_t> first_frequency;
	std::unordered_map<char, std::size_t> second_frequency;

	for(const char& x: first) {
		first_frequency[x] += 1;
	}
	for(const char& x: second) {
		second_frequency[x] += 1;
	}

	std::cout << "One " <<
		"is" << (first_frequency == second_frequency ? "" : "n't") << " a permutation of other" << std::endl;
}