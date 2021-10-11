#include <iostream>

struct Implicit {
    template<typename T>
    Implicit(T t) {
        std::cout << t << '\n';
    }
};

struct Explicit {
    template<typename T>
    explicit Explicit(T t) {
        std::cout << t << '\n';
    }
};

int main() {
    Implicit imp1 = "implicit";
//  Explicit exp1 = "implicit";
    Explicit exp2{"explicit"};
}
