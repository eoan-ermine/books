#include <iostream>
#include <cstdint>
#include <memory>
#include <new>

struct Base {
	Base() {
		std::cout << "Hello\n";
	}
	~Base() {
		std::cout << "Bye\n";
	}

	static void* operator new(std::size_t size) {
		if (size != sizeof(Base)) {
			return ::operator new(size);
		}
		void* memory = std::malloc(size);
		return memory;
	}
	static void operator delete(void* rawMemory) {
		if (rawMemory == nullptr) return;
		std::free(rawMemory);
	}
};

struct Derived: Base { };

int main() {
	Base* obj = new Base;
	delete obj;
}
