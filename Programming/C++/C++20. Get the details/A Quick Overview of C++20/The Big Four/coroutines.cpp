Generator<int> getNext(int start = 0, int step = 1) {
    auto value = start;
    while(true) {
        co_yield value;
        value += step;
    }
}

int main() {
    std::cout << '\n';

    std::cout << "getNext(): ";
    auto gen1 = getNext();
    for(int i = 0; i <= 10; ++i) {
        gen1.next();
        std::cout << " " << gen1.getValue();
    }

    std::cout << "\n\n";

    std::cout << "getNext(100, -10): ";
    auto gen2 = getNext(100, -10);
    for(int i = 0; i <= 20; ++i) {
        gen2.next();
        std::cout << " " << gen2.getValue();
    }

    std::cout << "\n";
}
