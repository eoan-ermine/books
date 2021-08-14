#include <memory>
#include <string>
#include <cstdlib>
#include <iostream>

void malloc_free() {
	constexpr std::size_t size = 5;
	if (auto ptr = reinterpret_cast<std::string*>(
		 std::malloc(size * sizeof(std::string)))) { // Allocating storage
		try {
			for(std::size_t i = 0; i < size; ++i) {
				std::construct_at(ptr + i, 5, 'a' + i); // Initializing objects
			}
			for(std::size_t i = 0; i < size; ++i) {
				std::cout << "ptr[" << i << "] == " << ptr[i] << '\n';
			}
			std::destroy_n(ptr, size);	// Calling destructor for each object
		} catch (...) { }
		std::free(ptr);	// Deallocating storage
	}
}

void new_delete() {
	constexpr std::size_t size = 5;

	std::string* ptr = new std::string[5]; // Allocating, initializing
    for(std::size_t i = 0; i < size; ++i) {
        ptr[i] = std::string(5, 'a' + i);
    }
	for(std::size_t i = 0; i < size; ++i) {
		std::cout << "ptr[" << i << "] == " << ptr[i] << '\n';
	}
	delete[] ptr; // Deallocating, calling destructor
}

int main() {
	malloc_free();
	new_delete();
}

