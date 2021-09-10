#include <cstddef>

template<std::size_t N>
void BinarySum(bool A[N], bool B[N], bool C[N + 1]) {
	// Precondition: elements of C are false-initialized
	for(std::size_t i = N - 1; i >= 0; --i) {
		bool a = A[i], b = B[i];
		C[i + 1] += a ^ b;
		C[i] += a && b;
	}
}
