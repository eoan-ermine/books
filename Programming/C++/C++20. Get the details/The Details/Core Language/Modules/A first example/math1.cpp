module;

// The code in the global module fragment
// is not exported by the module interface

#include <numeric>
#include <vector>

export module math;

export int add(int a, int b) {
	return a + b;
}

export int getProduct(const std::vector<int>& vec) {
	return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
}
