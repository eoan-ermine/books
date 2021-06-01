#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string original_expression, new_expression;
	std::getline(std::cin, original_expression);

	int count_of_one = 0;
	int count_of_two = 0;
	int count_of_three = 0;

	for(const char& x: original_expression) {
		if(x == '1') ++count_of_one;
		else if(x == '2') ++count_of_two;
		else if(x == '3') ++count_of_three;
	}

	bool any = count_of_two || count_of_three;

	for(int i = 0; i < count_of_one; ++i) {
		new_expression.push_back('1');
		if(i != count_of_one - 1 || any) {
			new_expression.push_back('+');
		}
	}

	any = count_of_three;
	for(int i = 0; i < count_of_two; ++i) {
		new_expression.push_back('2');
		if(i != count_of_two - 1 || any) {
			new_expression.push_back('+');
		}
	}

	any = false;
	for(int i = 0; i < count_of_three; ++i) {
		new_expression.push_back('3');
		if(i != count_of_three - 1) {
			new_expression.push_back('+');
		}
	}

	std::cout << new_expression;
}
