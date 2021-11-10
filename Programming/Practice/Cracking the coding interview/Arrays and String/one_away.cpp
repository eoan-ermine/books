#include <string>
#include <iostream>
#include <unordered_map>

#include <cmath>

bool is_one_away(const std::string& a, const std::string& b) {
	std::unordered_map<char, int> a_freq;
	std::unordered_map<char, int> b_freq;

	for(const char& x: a) {
		a_freq[x] += 1;
	}
	for(const char& x: b) {
		b_freq[x] += 1;
	}

	bool allow_collision = true;
	for(const auto& [key, value]: a_freq) {
		if(b_freq[key] != value) {
			if(allow_collision && std::abs(b_freq[key] - value) == 1) {
				allow_collision = false;
				continue;
			}
			return false;
		}
	}
	return true;
}

int main() {
	std::string first, second;

	std::getline(std::cin, first);
	std::getline(std::cin, second);

	std::cout << is_one_away(first, second) << std::endl;
}