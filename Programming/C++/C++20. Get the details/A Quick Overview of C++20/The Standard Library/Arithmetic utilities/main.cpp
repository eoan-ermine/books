#include <iostream>
#include <utility>
#include <cstdint>

#include <bitset>
#include <bit>

int main() {
    int x = -3;
    unsigned int y = 7;

    if (x < y) std::cout << "expected\n";
    else std::cout << "not expected\n";

    if (std::cmp_less(x, y)) std::cout << "expected";
    else std::cout << "not expected";

    std::uint8_t num = 0b10110010;

    std::cout << std::has_single_bit(num) << '\n'; // false
    std::cout << std::bit_width(unsigned(5)) << '\n'; // 3
    std::cout << std::bitset<8>(std::rotl(num, 2)) << '\n'; // 11001010
    std::cout << std::bitset<8>(std::rotr(num, 2)) << '\n'; // 10101100
}
