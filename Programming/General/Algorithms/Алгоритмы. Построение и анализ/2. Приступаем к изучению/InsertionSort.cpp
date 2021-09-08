#include <cstdint>

template<typename T, std::size_t N>
void insertionSort(T a[N]) {
	for(std::size_t j = 1; j != N; ++j) {
		T key = A[j];
		std::size_t i = j - 1;
		while(i >= 0 && A[i] > key) {
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
}
