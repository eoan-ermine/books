#include <string>

template<class T>
class NamedPtr {
	std::string name;
	T* ptr;
public:
	NamedPtr(const std::string& initName, T* initPtr);
};

template<class T>
NamedPtr<T>::NamedPtr(const std::string& initName, T* initPtr)
	: name(initName), ptr(initPtr) { }

// ^ It's good, assignment in constructor is bad
// But sometimes we have something like this:

class ManyDataMbrs {
public:
	ManyDataMbrs();
	ManyDataMbrs(const ManyDataMbrs& x);
private:
	int a, b, c, d, e, f, g, h;
	double i, j, k, l, m;
};

// We wanna initialize with some numbers even we use copy constructor

ManyDataMbrs::ManyDataMbrs()
	: a(1), b(1), c(1), d(1), e(1), f(1), g(1), h(1) { }

// And we can use delegating constructor!

ManyDataMbrs::ManyDataMbrs(const ManyDataMbrs& x): ManyDataMbrs() { }

int main() { }