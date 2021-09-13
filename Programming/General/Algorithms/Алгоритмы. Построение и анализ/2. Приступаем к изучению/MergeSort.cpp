#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>

template<typename T>
void merge_sort(T array[], std::size_t size) noexcept {
	if(size > 1) {
		const std::size_t left_size = size / 2;
		const std::size_t right_size = size - left_size;

		merge_sort(&array[0], left_size);
		merge_sort(&array[left_size], right_size);

		std::size_t lidx = 0, ridx = left_size, idx = 0;
		std::unique_ptr<T[]> tmp_array(new T[size]);

		while(lidx < left_size || ridx < size) {
			tmp_array[idx++] = std::move(
				array[lidx] < array[ridx] ? array[lidx++] : array[ridx++]
			);
			if(lidx == left_size) {
				std::copy(
					std::make_move_iterator(&array[ridx]),
					std::make_move_iterator(&array[size]),
					&tmp_array[idx]
				);
				break;
			}
			if(ridx == size) {
				std::copy(
					std::make_move_iterator(&array[lidx]),
					std::make_move_iterator(&array[left_size]),
					&tmp_array[idx]
				);
				break;
			}
		}
		std::copy(
			std::make_move_iterator(tmp_array),
			std::make_move_iterator(&tmp_array[size]),
			array
		);
	}
}
