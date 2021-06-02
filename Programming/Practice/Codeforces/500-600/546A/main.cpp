#include <iostream>

int calculateSum(int a1, int an, int n) {
	return (a1 + an) / 2.0 * n;
}

int main() {
	int k, n, w; std::cin >> k >> n >> w;
	int cost = calculateSum(k, w * k, w);
	std::cout << (cost <= n ? 0 : cost - n);
}
