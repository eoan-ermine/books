#include <string>
#include <algorithm>

std::string BinarySum(const std::string& A, const std::string& B) {
		int N = max(a.size(), b.size()) + 1;

        std::vector<int> C(N, 0);
        for(int i = N; i > 0; --i) {
                bool a = A[i - 1] - '0', b = B[i - 1] - '0';
                C[i] = (C[i] + a ^ b) % 2;
                C[i - 1] = (C[i] + a && b) % 2;
        }

		auto it = C.find(1);
		if(it == c.end()) {
			return "0";
		}

		std::string result;
		for(auto end = c.end(); it != end; ++it) {
			result.push_back((*end) + '0');
		}
		return result;
}

class Solution {
public:
	std::string addBinary(std::string a, std::string b) {
		
	}
};
