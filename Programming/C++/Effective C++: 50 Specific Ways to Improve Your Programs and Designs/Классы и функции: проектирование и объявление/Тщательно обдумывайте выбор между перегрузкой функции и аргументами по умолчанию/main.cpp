#include <limits>
#include <string>

int max(int a,
		int b = std::numeric_limits<int>::min(),
		int c = std::numeric_limits<int>::min(),
		int d = std::numeric_limits<int>::min(),
		int e = std::numeric_limits<int>::min())
{
	int temp = a > b ? a : b;
	temp = temp > c ? temp : c;
	temp = temp > d ? temp : d;
	return temp > e ? temp : e;
}

// Если вы достаточно разумно выберете аргумент со
// значением по умолчанию и намерены использовать
// только один алгоритм, вам следует прибегнуть
// к аргументу по умолчанию

// Выше ок.
// Modern C++ Extra:

template<typename T, typename... Args>
constexpr T max(T&& a, decltype(a) b, Args&&... args) {
	if(sizeof...(args) == 0) {
		return a > b ? a : b;
	}
	return max(max(std::forward<T>(a), std::forward<T>(b)), std::forward<Args>(args)...);
}

// А ниже мы не имеем внятного аргумента по
// умолчанию и поэтому делаем перегрузку

double avg(int a);
double avg(int a, int b);
double avg(int a, int b, int c);
double avg(int a, int b, int c, int d);
double avg(int a, int b, int c, int d, int e);

// Modern C++ Extra:

template<typename Ret = double, typename... Args>
constexpr double avg(Args&&... args) {
	return static_cast<Ret>((... + std::forward<Args>(args))) / sizeof...(args);
}

class Natural {
public:
	Natural(int initValue);
	Natural(const Natural& rhs);
private:
	unsigned int value;
	
	void init(int initValue);
	void error(const std::string& msg) { }
};

// To prevent boilerplate
inline void Natural::init(int initValue) {
	value = initValue;
}

Natural::Natural(int initValue) {
	if(initValue > 0) init(initValue); // here we need to validate
	else error("illegal initial value");
}

inline Natural::Natural(const Natural& x) {
	init(x.value); // here we not
}

int main() {
	constexpr double maximum = max<>(2.0, 3.0, 5.0);
	static_assert(maximum == 5.0);

	constexpr double average = avg<double>(2.0, 3.0, 5.0);
	static_assert(average == (10.0 / 3));
}