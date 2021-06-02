#include <iostream>
#include <vector>
#include <string>

#include <utility>

enum class Gender {
        MALE = 'B',
        FEMALE = 'G',
};

int main() {
        int n, t; std::cin >> n >> t; std::cin.ignore();
        std::string start; std::getline(std::cin, start);

        std::vector<Gender> queue;
        for(const char& x: start) {
                if(x == static_cast<char>(Gender::MALE)) queue.push_back(Gender::MALE);
                else queue.push_back(Gender::FEMALE);
        }

        std::vector<std::pair<int, int>> moves;
        for(int i = 0; i < t; ++i) {
                for(int j = 0; j < n - 1; ++j) {
                        if(queue[j] == Gender::MALE && queue[j + 1] == Gender::FEMALE) {
                                moves.push_back(std::pair<int, int>(j, j + 1));
                        }
                }
                for(const std::pair<int, int>& pair: moves)
                        std::swap(queue[pair.first], queue[pair.second]);
                moves.clear();
        }
        for(int i = 0; i < n; ++i) {
                std::cout << (queue[i] == Gender::MALE ? "B" : "G");
        }
}
