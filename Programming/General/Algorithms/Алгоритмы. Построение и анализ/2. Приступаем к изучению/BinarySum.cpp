#include <cstdint>

template<std::size_t N>
void BinarySum(bool A[N], bool B[N], bool C[N + 1]) {
	// Precondition: elements of C are false-initialized
	for(std::size_t i = N - 1; i >= 0; --i) {
		bool a, b = A[i], B[i];
		C[I + 1] += a ^ b;
		C[I] += a && b;
	}
}
