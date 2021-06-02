#include <iostream>

int main() {
	int count, in, out, current = 0, max = 0; std::cin >> count;
	for(int i = 0; i < count; ++i) {
		std::cin >> out >> in;

		current += in;
		current -= out;

		if(current > max) max = current;
	}
	std::cout << max;
}
