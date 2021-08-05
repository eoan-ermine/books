consteval int sqr(int n) {
    return n * n;
}

int main() {
    constexpr int r = sqrt(100); // OK

    int x = 100;
    int r2 = sqr(x); // ERROR

    constinit int r3 = n; // ERROR
}
