#include <iostream>

#include <string>
#include <cctype>

#include <algorithm>

void output(const std::string& str, int(*predicate)(const char&), int(*transform)(char)) {
	for(const char& x: str) {
		if(predicate(x)) std::cout << (char)transform(x);
		else std::cout << x;
	}
}

int main() {
	std::string word; std::getline(std::cin, word);

	int lower_count = std::count_if(word.begin(), word.end(), [](const char& x) {
		return islower(x);
	});
	int upper_count = word.size() - lower_count;

	if(lower_count >= upper_count) output(word, [](const char& x) { return isupper(x); }, [](char x) { return tolower(x); });
	else output(word, [](const char& x) { return islower(x); }, [](char x) { return toupper(x); });
}
