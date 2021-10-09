class B;
class A {
public:
	A() { }
	A(const B&) { }
};
class B {
public:
	operator A() const { return A{}; }
};

void f(const A&) { }

struct A1 {
public:
	int doIt() {
		return 1;
	}
};

struct B1 {
public:
	int doIt() {
		return 2;
	}
};

struct Derived: A1, B1 { };

struct A2 {
	int doIt() {
		return 1;
	}
};

class B2 {
	int doIt() {
		return 2;
	}
};

struct Derived: A2, B2 {};

int main() {
	B b;
//	f(b) -- Ambiguity

	Derived d;
//	d.doIt() -- Ambiguity

	d.A1::doIt();
	d.B1::doIt();

	Derived d;
//	int i = d.doIt(); -- Ambiguity
}