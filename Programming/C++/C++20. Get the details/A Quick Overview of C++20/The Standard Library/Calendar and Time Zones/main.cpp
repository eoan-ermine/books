#include <iostream>
#include <chrono>

using namespace std::chrono;

int main() {
    auto time = floor<milliseconds>(system_clock::now());
    auto localTime = zoned_time<milliseconds>(current_zone(), time);
    auto berlinTime = zoned_time<milliseconds>("Europe/Berlin", time);
    auto newYorkTime = zoned_time<milliseconds>("America/New_York", time);
    auto tokyoTime = zoned_time<milliseconds>("Asia/Tokyo", time);

    std::cout << time << '\n';
    std::cout << localTime << '\n';
    std::cout << berlinTime << '\n';
    std::cout << newYorkTime << '\n';
    std::cout << tokyoTime << '\n';
}
