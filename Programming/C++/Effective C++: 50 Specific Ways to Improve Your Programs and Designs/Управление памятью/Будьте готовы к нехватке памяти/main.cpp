#include <iostream>
#include <cstdint>
#include <new>

void new_handler() {
	std::cout << "Unable to satisfy request for memory, terminating\n";
	std::terminate();
}

void trying_make_available_more_space() {
	// Try make available more space
	// If this function returns, allocating function repeats allocating try
}

void notify_new_handler() {
	std::cout << "Unable to satisfy request for memory, terminating\n";
	std::set_new_handler(nullptr);
}

int main() {
	constexpr std::size_t count = 10000000000;

	std::set_new_handler(notify_new_handler);
	try {
		int *pBigDataArray = new int[count];
	} catch (const std::bad_alloc& e) {
		std::cout << "Catched " << e.what() << '\n';
	}

	std::cout << "Successfully allocated " << count << " integers\n";
}
