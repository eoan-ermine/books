#include <iostream>
#include <string>

int main() {
	int last = -999, current_max = 0, total_max = 0, current, n;
	std::cin >> n;

	for(int i = 0; i < n; ++i) {
		std::cin >> current;
		if(current >= last) { current_max += 1; }
		else {
			if(current_max > total_max) total_max = current_max;
			current_max = 1;
		}
		last = current;
	}
	if(current_max > total_max) total_max = current_max;

	std::cout << total_max;
}
