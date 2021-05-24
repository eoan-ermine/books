#include <iostream>

#include <ranges>
#include <numeric>

#include <vector>

int main() {
    int result = 0;
    for(int i = 1; i < 1000; ++i) if(i % 3 == 0 || i % 5 == 0) result += i;
    std::cout << result << std::endl;

    // Functional-style version (C++20):

    auto values = std::ranges::filter_view(std::ranges::iota_view(1, 1000), [](int i) { return i % 3 == 0 || i % 5 == 0; });
    std::cout << std::accumulate(values.begin(), values.end(), 0) << std::endl;

    // Functional-style version (C++19):

    std::vector<int> numbers(999);
    std::iota(numbers.begin(), numbers.end(), 1);
    std::cout << std::accumulate(numbers.begin(), numbers.end(), 0, [](int a, int b) { return (b % 3 == 0 || b % 5 == 0) ? a + b : a; }) << std::endl;
}