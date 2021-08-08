#include <concepts>

template<typename T> requires std::integral<T>
auto gcd(T a, T b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

std::integral auto gcd1(std::integral auto a, std::integral auto b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() { }
