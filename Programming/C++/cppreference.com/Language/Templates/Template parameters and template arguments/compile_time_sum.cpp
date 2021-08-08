#include <iostream>

template<auto... args> struct sum {
	const static int value = (... + args);
};

int main() {
	std::cout << sum<1, 2, 'a', 'b'>::value;
}
