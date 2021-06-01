#include <iostream>

int main() {
	int n, k;
	int place_counter = 0, current_score = 0, last_score = 0, participant_counter = 0;
	std::cin >> n >> k;

	for(int i = 1; i <= n; ++i) {
		std::cin >> current_score;

		if(i > k) {
			if(current_score < last_score) break;
		}
		if(current_score <= 0) break;

		last_score = current_score;
		++participant_counter;
	}
	std::cout << participant_counter;
}
