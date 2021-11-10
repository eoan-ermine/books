#include <string>
#include <unordered_map>
#include <iostream>

int main() {
	std::string line;
	std::getline(std::cin, line);

	const std::size_t size = line.size();
	std::size_t middle_idx = size / 2;
	
	bool okay = true;
	bool allow_collision = true;

	std::unordered_map<char, int> frequency;
	for(auto idx = 0; idx != size; ++idx) {
		if(line[idx] == ' ') {
			continue;
		}
		frequency[line[idx]] += 1;
	}

	for(const auto& [_, value]: frequency) {
		if(value % 2) {
			if(!allow_collision) {
				okay = false;
				break;
			}
			allow_collision = false;
		}
	}

	std::cout << okay << std::endl;
}