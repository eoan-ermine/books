module math;

#include <numeric>

namespace math {
	int add(int a, int b) {
		return a + b;
	}
	int getProduct(const std::vector<int>& vec) {
		return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
	}
}
