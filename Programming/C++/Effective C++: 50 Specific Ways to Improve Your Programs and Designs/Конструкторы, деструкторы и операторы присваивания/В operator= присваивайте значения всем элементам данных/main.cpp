#include <iostream>

class Base {
public:
	Base(int initialValue = 0): x(initialValue) { }

	friend std::ostream& operator<<(std::ostream& os, Base& object);
private:
	int x;
};

std::ostream& operator<<(std::ostream& os, Base& object) {
	os << "Base(" << object.x << ")";
	return os;
}

class Derived: public Base {
public:
	Derived(int initialValue): Base(initialValue), y(initialValue) { }
	Derived& operator=(const Derived& rhs);

	friend std::ostream& operator<<(std::ostream& os, Derived& object);
private:
	int y;
};

std::ostream& operator<<(std::ostream& os, Derived& object) {
	operator<<(os, static_cast<Base&>(object));
	os << " " << "Derived(" << object.y << ")";
	return os;
}

Derived& Derived::operator=(const Derived& rhs) {
	if (this == &rhs) return *this;

	// Base::operator=(rhs); // Uncomment to get desired behavior
	y = rhs.y;

	return *this;
}

struct OtherBase {
	OtherBase(int initialValue = 0): x(initialValue) { }
	OtherBase(const OtherBase& rhs): x (rhs.x) { }
private:
	int x;
};

struct OtherDerived: public OtherBase {
	OtherDerived( int initialValue = 0): OtherBase(initialValue), y(initialValue) { }
	OtherDerived(const OtherDerived& rhs) : /* OtherBase(rhs), - uncomment to get correct code*/ y(rhs.y) { }
private:
	int y;
};

int main() {
	Derived d1(0);
	std::cout << d1 << '\n';

	Derived d2(1);
	std::cout << d2 << '\n';

	d1 = d2;
	std::cout << d1;
}