#include <iostream>
#include <vector>

template <typename>
struct Other;

template <>
struct Other<std::vector<int>> { };

template<typename T>
concept TypeRequirement = requires {
	typename T::value_type;
	typename Other<T>;
};

int main() {
	TypeRequirement auto myVec = std::vector<int>{1, 2, 3};
}
