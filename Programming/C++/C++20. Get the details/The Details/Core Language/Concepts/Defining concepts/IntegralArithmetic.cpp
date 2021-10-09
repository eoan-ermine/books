#include <iostream>
#include <numeric>

template<typename T>
concept Integral = std::is_integral_v<T>;

template<typename T>
concept SignedIntegral = Integral<T> && std::is_signed_v<T>;

template<typename T>
concept UnsignedIntegral = Integral<T> && !SignedIntegral<T>;

template<typename T>
concept Arithmetic = std::is_integral_v<T> || std::is_floating_point_v<T>;

void func(SignedIntegral auto integral) {
	std::cout << "SignedIntegral: " << integral << '\n';
}

void func(UnsignedIntegral auto integral) {
	std::cout << "UnsignedIntegral: "  << integral << '\n';
}

int main() {
	func(-5);
	func(5u);
}
