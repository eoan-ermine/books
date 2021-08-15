#include <cstring>
#include <iostream>

class Rational {
	int num, den;
public:
	Rational(int numerator = 0, int denominator = 1)
		: num(numerator), den(denominator) { }
	
	int numerator() const {
		return num;
	}
	int denominator() const {
		return den;
	}

	/*
	const Rational operator*(const Rational& rhs) const {
		return Rational{this->num * rhs.num,
						this->den * rhs.den};
	}

 	^ Shit:
		>> Rational{2, 1} * 2 -- valid expression
		>> 2 * Rational{2, 1} -- not
	*/
};

// Good:
const Rational operator*(const Rational& lhs, const Rational& rhs) {
		return Rational{lhs.numerator() * rhs.numerator(),
						rhs.denominator() * rhs.denominator()};
}

// Нет нужды объявлять другом, потому что все необходимое
// можем получить из публичного интерфейса

// operator<< и operator>> не могут быть объявлены
// членами класса, потому что требуют писать так:

/*
	a << std::cout;
	a >> std::cin;
*/

class String {
	const char* data;
public:
	String() { }
	String(const char* value) {
		char* buffer = new char[std::strlen(value) + 1];
		std::strcpy(buffer, value);
		this->data = buffer;
	}
	String& operator=(const char* rhs) {
		char* buffer = new char[std::strlen(rhs) + 1];
		std::strcpy(buffer, rhs);
		this->data = buffer;
		return *this;
	}
	~String() {
		delete[] data;
	}

	friend std::istream& operator>>(std::istream& input, String& string);
	friend std::ostream& operator<<(std::ostream& output, String& string);
};

std::istream& operator>>(std::istream& input, String& string) {
	char* buffer = new char[1024];
	
	input.getline(buffer, 1024);
	string = buffer;

	return input;
}

std::ostream& operator<<(std::ostream& output, String& string) {
	return output << string.data;
}

int main() {
	String string;
	
	std::cin >> string;
	std::cout << string;
}