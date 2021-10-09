struct Rational {
	Rational() = default;
	Rational(const Rational&) = default;
	Rational& operator=(const Rational&) = default;
};

const Rational operator*(const Rational& lhs, const Rational& rhs) {
	return Rational { };
}

int main() {
	char* write_write{nullptr};
	char* const write_read{nullptr};
	const char* read_write{nullptr};
	const char* const read_read{nullptr};

	Rational a, b, c;
	(a * b) = c; // const result type in operator*
	// forbids that shit
}

// Btw, we have mutable