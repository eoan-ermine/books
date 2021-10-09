#include <string>
#include <iostream>

#include <cstddef>

void f(int x) {
	std::cout << "f(int x)\n";
}
void f(long int x) {
	std::cout << "f(long int x)\n";
}
void f(std::string* ps) {
	std::cout << "f(std::string* ps)\n";
}

class NullPointer {
public:
	template<class T>
	operator T*() const {
		return 0;
	}
	template<class C, class T>
	operator T C::*() const {
		return 0;
	}
private:
	void operator&() const;
};

struct Example {
	int x();
};

void d(int (Example::*ptr)(void)) {
	std::cout << "d(int (Example::*ptr)(void)\n";
}

static NullPointer null;

int main() {
	// Okay, just don't pass 0 with meaning "null pointer"
	// use appropriate literal with meaning "null pointer":
	// nullptr

	f(0);
	f(NULL);

	f(static_cast<std::string*>(0));
	f(static_cast<std::string*>(NULL));
	f(null);

	d(null);
}