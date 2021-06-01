#include <iostream>

int main() {
	int w; bool found = false; std::cin >> w;
	for(int i = 2; i < w; i += 2) {
		for(int j = 2; j < w; j += 2) {
			if(i + j == w) { found = true; break; }
		}
	}
	std::cout << (found ? "YES" : "NO");
}
