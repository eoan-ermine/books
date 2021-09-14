#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> digits) {
		digits.back() += 1;
		for(auto it = digits.rbegin(); it != digits.rend() - 1; ++it) {
			bool overflow = (*it) / 10;

			*it %= 10;
			*(it + 1) += overflow;
		}

		bool overflow = digits.front() / 10;
		if(overflow) {
			digits.resize(digits.size() + 1);
			std::copy(
				digits.begin(),
				digits.end() - 1,
				digits.begin() + 1
			);
			digits[0] = 1;
			digits[1] %= 10;
		}

		return digits;
	}
};
