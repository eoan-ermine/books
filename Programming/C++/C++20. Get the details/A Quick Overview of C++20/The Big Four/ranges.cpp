#include <ranges>

int main() {
    std::vector<int> ints{0, 1, 2, 3, 4, 5};

    auto even = [](int i){ return i % 2 == 0; };
    auto square = [](int i){ return i * i; };

    for(int i: ints | std::views::filter(even) | std::views::transform(square)) {
        std::cout << i << ' ';
    }
}
