#include <iostream>

int main() {
	int n, h, required_width = 0, height; std::cin >> n >> h;
	for(int i = 0; i < n; ++i) {
		std::cin >> height;
		if(height > h) required_width += 2;
		else required_width += 1;
	}
	std::cout << required_width;
}
