#include <cstddef>
#include <algorithm>
#include <iostream>

void SelectionSort(int* a, size_t n) {
	for(size_t i = 0; i < n - 1; ++i) {
		std::swap(
			*std::min_element(a + i, a + n),
			a[i]
		);
	}
}

int main() {
	int A[5] = {5, 4, 3, 2, 1};
	SelectionSort(A, 5);
	for(auto x: A) {
		std::cout << x << ' ';
	}
}
