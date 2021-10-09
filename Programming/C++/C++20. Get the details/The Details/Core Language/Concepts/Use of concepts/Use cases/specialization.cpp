#include <concepts>
#include <iostream>

template<typename T>
struct Vector {
	Vector() {
		std::cout << "Vector<T>" << '\n';
	}
};

template<std::regular Reg>
struct Vector<Reg> {
	Vector() {
		std::cout << "Vector<std::regular>" << '\n';
	}
};

int main() {
	Vector<int> vec;
	Vector<int&> vec2;
}
