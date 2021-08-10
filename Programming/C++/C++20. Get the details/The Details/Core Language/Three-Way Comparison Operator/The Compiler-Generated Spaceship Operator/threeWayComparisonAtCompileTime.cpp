#include <compare>
#include <iostream>

struct MyDouble {
	double value;
	explicit constexpr MyDouble(double value): value{value} { }
	auto operator<=>(const MyDouble&) const = default;
};

int main() {
	constexpr MyDouble myDouble1{2011};
	constexpr MyDouble myDouble2{2014};

	constexpr bool res = myDouble1 < myDouble2;
}
