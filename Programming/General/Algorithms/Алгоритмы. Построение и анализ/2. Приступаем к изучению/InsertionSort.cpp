#include <cstddef>

template<typename T, std::size_t N>
void insertionSort(T a[N]) {
	for(std::size_t j = 1; j != N; ++j) {
		T key = a[j];
		std::size_t i = j - 1;
		while(i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;
	}
}
