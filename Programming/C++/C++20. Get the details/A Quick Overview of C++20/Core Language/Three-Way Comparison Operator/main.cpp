#include <compare>
struct MyInt {
    int value;
    MyInt(int value): value{value} { }
    auto operator<=>(const MyInt&) const = default;
};
