#include <concepts>
#include <iostream>

template<typename T> requires std::integral<T>
auto gcd(T a, T b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

template<typename T>
auto gcd1(T a, T b) requires std::integral<T> {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

template<std::integral T>
auto gcd2(T a, T b) {
	if (b == 0) return a;
	else return gcd2(b, a % b);
}

auto gcd3(std::integral auto a, std::integral auto b) {
	if (b == 0) return a;
	else return gcd3(b, a % b);
}

int main() {
	gcd(100, 10);
	gcd1(100, 10);
	gcd2(100, 10);
	gcd3(100, 10);
}