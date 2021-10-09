class Rational {
public:
	Rational(int numerator, int denominator = 1) {}
	~Rational {}

	/*
	FUCKING SHIT:

	friend const Rational& operator*(const Rational& lhs, const Rational& rhs) {
		Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
		return result;
	}
	*/

	/*
	ANOTHER FUCKING SHIT:

	friend const Rational& operator*(const Rational& lhs, const Rational& rhs) {
		Rational* result = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
		return *result;
	}
	*/
private:
	int n, d;
};

int main() {
	// BECAUSE OF (variant with new)

	/*
		const Rational& four = two * two;
		-- no delete here
		MEMORY LEAK!
	*/

	/*
		Rational one(1), two(2), three(3), four(4);
		Rational product;
		product = one * two * three * four;
		FUCKING MEMORY LEAK!
	*/

	/*
		YOU FORCE TO WRITE THIS FUCKING SHIT:

		const Rational& temp1 = one * two;
		const Rational& temp2 = temp1 * three;
		const Rational& temp3 = temp2 * for;

		delete &temp1;
		delete &temp2;
		delete &temp3;
	*/
}