#include <iostream>
#include <string>

int main() {
	std::string instruction; std::getline(std::cin, instruction);
	bool flag = false;
	for(const char& x: instruction) {
		if(x == 'H' || x == 'Q' || x == '9') { flag = true; break; }
	}
	std::cout << (flag ? "YES" : "NO");
}
