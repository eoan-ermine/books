#include <iostream>
#include <string>

int main() {
	std::string situation; std::getline(std::cin, situation);

	int current_max = 1, max = 1;
	char previous = '\0';

	for(int i = 0; i < situation.size(); ++i) {
		if(situation[i] == previous) current_max += 1;
		else {
			if(current_max > max) max = current_max;
			current_max = 1;
		}
		previous = situation[i];
	}
	if(current_max > max) max = current_max;

	std::cout << (max >= 7 ? "YES" : "NO");
}
