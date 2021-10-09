#include <cstddef>

template<typename T, std::size_t N>
int LinearSearch(T array[N], T toFind) {
	for(std::size_t idx = 0; idx != N; ++idx) {
		if(array[idx] == toFind) return idx;
	}
	return -1;
}
