#include <iostream>
#include <string>

int main() {
	int n, a = 0, d = 0; std::cin >> n; std::cin.ignore();
	std::string script; std::getline(std::cin, script);

	for(const char& x: script) {
		if(x == 'A') ++a;
		else if(x == 'D') ++d;
	}

	if(a > d) std::cout << "Anton";
	else if(d > a) std::cout << "Danik";
	else std::cout << "Friendship";
}
