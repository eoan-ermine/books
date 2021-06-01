#include <iostream>
#include <string>

int main() {
	std::string input, used; std::getline(std::cin, input);
	int count_of_characters = 0;

	for(auto it = input.begin(); it != input.end(); ++it) {
		char ch = *it;
		if(used.find(ch) == std::string::npos) {
			used.push_back(ch);
			++count_of_characters;
		}
	}

	std::cout << (count_of_characters % 2 ? "IGNORE HIM!" : "CHAT WITH HER!");
}
