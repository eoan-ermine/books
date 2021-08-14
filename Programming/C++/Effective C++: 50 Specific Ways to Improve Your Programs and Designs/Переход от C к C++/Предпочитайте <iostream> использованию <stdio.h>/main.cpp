#include <iostream>

class Rational {
	int numerator, denominator;
public:
	Rational(int numerator = 0, int denominator = 1): numerator(numerator), denominator(denominator) { }

	friend std::ostream& operator<<(std::ostream&, const Rational&);
	friend std::istream& operator>>(std::istream&, Rational&);
};

std::ostream& operator<<(std::ostream& stream, const Rational& obj) {
	std::cout << obj.numerator << '/' << obj.denominator;
	return stream;
}

std::istream& operator>>(std::istream& stream, Rational& obj) {
	char delimiter;

	stream >> obj.numerator;

	if (stream.peek() != '/') {
		stream.setstate(std::ios::failbit);
	} else {
		stream.ignore(1);
	}

	stream >> obj.denominator;

	return stream;
}

int main() {
	int i;
	Rational r;

	std::cin >> i >> r;
	std::cout << i << ' ' << r;
}
