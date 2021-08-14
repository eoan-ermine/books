/*
	Bad shit:

	#define max(a, b) ((a) > (b) ? (a) : (b))

	int a = 5, b = 0;
	max(++a, b);		// a incremented twice
	max(++a, b + 10);	// a incremented once
*/

// Good
template<class T>
inline const T& max(const T& a, const T& b) {
	return a > b ? a : b;
}

/*
	Bad shit:

	#define AERODYNAMICS_COEF 1892.1
*/

// Good
template<typename T>
constexpr T AERODYNAMICS_COEF = T(1892.1); // (C++20) (or 17, i forgor)

// Another good example for old compiler
const double AERODYNAMICS_COEF_1 = 1892.1;

int main() { }
