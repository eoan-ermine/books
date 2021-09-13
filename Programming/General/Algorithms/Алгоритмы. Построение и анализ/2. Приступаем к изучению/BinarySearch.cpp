#include <cstddef>
#include <iostream>

using namespace std;

template<typename T>
bool BinarySearch(T array[], size_t size, const T& toFind) {
	if(size == 1) {
		return array[0] == toFind;
	}

	size_t half = size / 2;
	if(T halfElement = array[half]; halfElement > toFind) {
		return BinarySearch(array, half, toFind);
	} else if(halfElement < toFind) {
		return BinarySearch(array + half, size - half, toFind);
	} else {
		return true;
	}
}

int main() {
	int array[] = {1, 2, 3, 4, 5};
	for(int x: array) {
		cout << BinarySearch(array, 5, x) << ' ';
	}
}
