// Если вы пытаетесь вернуть ссылку на объект,
// который не живет достаточно долго - вы дурак
// и идиот. Возвращайте значение, если вам надо

class Rational {
public:
	Rational(int numerator = 0, int denominator = 1) {}
	friend inline const Rational operator*(const Rational& lhs, const Rational& rhs) {
		return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
	}
	// ^ Только Rational, никаких ссылок, черт тебя побери
private:
	int n, d;
};

int main() { }