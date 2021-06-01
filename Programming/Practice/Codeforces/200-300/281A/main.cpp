#include <iostream>
#include <cctype>

int main() {
	std::string word; std::getline(std::cin, word);

	std::cout << static_cast<unsigned char>(std::toupper(word[0]));
	for(int i = 1; i < word.size(); ++i) {
		std::cout << word[i];
	}
}
