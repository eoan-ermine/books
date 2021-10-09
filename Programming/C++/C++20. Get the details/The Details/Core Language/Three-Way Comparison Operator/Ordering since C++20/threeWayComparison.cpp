#include <compare>
#include <iostream>

struct MyInt {
	int value;
	explicit MyInt(int value): value{value} { }
	auto operator<=>(const MyInt& rhs) const {
		return value <=> rhs.value;
	}
};

struct MyDouble {
	double value;
	explicit constexpr MyDouble(double value): value{value} { }
	auto operator<=>(const MyDouble&) const = default;
};


int main() { }
