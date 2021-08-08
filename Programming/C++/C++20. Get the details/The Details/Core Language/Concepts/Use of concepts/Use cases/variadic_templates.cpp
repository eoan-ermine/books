#include <concepts>
#include <iostream>

template<std::integral... Args>
bool all(Args... args) { return (... && args); }

template<std::integral... Args>
bool any(Args... args) { return (... || args); }

template<std::integral... Args>
bool none(Args... args) { return not(... || args); }

int main() {
	std::cout << all(5, true, false) << std::endl;
	std::cout << any(5, true, false) << std::endl;
	std::cout << none(5, true, false) << std::endl;
}
