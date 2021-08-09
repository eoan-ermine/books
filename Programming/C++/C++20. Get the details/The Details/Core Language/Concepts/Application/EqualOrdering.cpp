#include <type_traits>
#include <concepts>
#include <algorithm>

template<typename T>
concept Eq = requires(T a, T b) {
	{ a == b } -> std::convertible_to<bool>;
	{ a != b } -> std::convertible_to<bool>;
};

template<typename T>
concept Ord = Eq<T> && requires(T a, T b) {
	{ a < b }  -> std::convertible_to<bool>;
	{ a <= b } -> std::convertible_to<bool>;

	{ a > b }  -> std::convertible_to<bool>;
	{ a >= b } -> std::convertible_to<bool>;

	{ std::max(a, b) } -> std::convertible_to<bool>;
};

template <Eq T>
bool areEqual(const T& a, const T& b) {
	return a == b;
}

template <Ord T>
T getSmaller(const T& a, const T& b) {
	return (a < b) ? a : b;
}

int main() { }

