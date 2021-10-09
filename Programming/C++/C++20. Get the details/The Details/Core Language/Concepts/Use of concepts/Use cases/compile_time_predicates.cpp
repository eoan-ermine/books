#include <compare>
#include <iostream>
#include <string>
#include <vector>

struct Test { };

int main() {
	std::cout << std::three_way_comparable<int> << std::endl;
	if (std::three_way_comparable<double>) { } else { }
	if constexpr (std::three_way_comparable<Test>) { } else { }
}
