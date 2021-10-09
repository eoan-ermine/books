#include <iostream>
struct Bad {
    Bad() { }
    // custom placement new
    static void* operator new(std::size_t sz, bool b) {
        std::cout << "custom placement new called, b = " << b << '\n';
        return ::operator new(sz);
    }
    // custom placement delete
    static void operator delete(void* ptr, bool b)
    {
        std::cout << "custom placement delete called, b = " << b << '\n';
        ::operator delete(ptr);
    }
};

struct Good {
    Good() { }
    // custom placement new
    static void* operator new(std::size_t sz, bool b=false) {
        std::cout << "custom placement new called, b = " << b << '\n';
        return ::operator new(sz);
    }
    // custom placement delete
    static void operator delete(void* ptr, bool b=false)
    {
        std::cout << "custom placement delete called, b = " << b << '\n';
        ::operator delete(ptr);
    }
};

struct AnotherGood {
    AnotherGood() { }
    // custom placement new
    static void* operator new(std::size_t sz, bool b) {
        return ::operator new(sz);
    }
	static void* operator new(std::size_t sz) {
		return ::operator new(sz);
	}
    // custom placement delete
    static void operator delete(void* ptr, bool b)
    {
        ::operator delete(ptr);
    }
	static void operator delete(void* ptr)
	{
		::operator delete(ptr);
	}
};


int main() {
	Bad* b1 = new (true) Bad;
	Bad* b2 = new Bad; // Error

	Good* g1 = new (true) Good;
	Good* g2 = new Good;

	AnotherGood* ag1 = new (true) AnotherGood;
	AnotherGood* ag2 = new AnotherGood;
}
