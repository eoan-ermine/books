#include <type_traits>

template<typename T>
concept Integral = std::is_integral_v<T>;

template<typename T>
concept SignedIntegral = Integral<T> && std::is_signed_v<T>;

// template<typename T>
// concept UnsignedIntegral = Integral<T> && !SignedIntegral<T>;

template<typename T>
concept UnsignedIntegral = Integral<T> && requires(T) {
	requires !SignedIntegral<T>;
};

int main() {
	UnsignedIntegral auto n = 5u;
//  UnsignedIntegral auto m = 5;
}
