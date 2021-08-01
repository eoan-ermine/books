#include <iostream>

template<typename T>
concept Integral = std::is_integral<T>::value;

Integral auto gcd(Integral auto a, Integral auto b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

template<typename T>
    requires Integral<T>
T gcd_other_syntax(T a, T b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() { }
