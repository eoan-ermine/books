#include <iostream>
#include <string>

int main() {
	int n; std::cin >> n;
	std::string word;

	std::cin.ignore();
	for(int i = 0; i < n; ++i) {
		std::getline(std::cin, word);
		int size = word.size();
		if(size > 10) std::cout << word.front() << size - 2 << word.back() << std::endl;
		else std::cout << word << std::endl;
	}
}


