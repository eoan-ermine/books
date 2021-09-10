#include <cstddef>
#include <iostream>

void BinarySum(bool* A, bool* B, int* C, size_t N) {
	// Precondition: elements of C are false-initialized
	for(int i = N; i > 0; --i) {
		bool a = A[i - 1], b = B[i - 1];
		C[i] = (C[i] + a ^ b) % 2;
		C[i - 1] = (C[i] + a && b) % 2;
	}
}

int main() {
	bool A[5] = {1, 0, 1, 0, 1};
	bool B[5] = {0, 1, 1, 0, 1};
	int C[6] = {0, 0, 0, 0, 0, 0};

	BinarySum(A, B, C, 5);
	for(auto x: C) {
		std::cout << x;
	}
	std::cout << std::endl;

	bool A1[4] = {0, 0, 0, 1};
	bool B1[4] = {0, 0, 1, 0};
	int C1[4] = {0};

	BinarySum(A1, B1, C1, 4);
	for(auto x: C1) {
		std::cout << x;
	}
	std::cout << std::endl;

	bool A2[5] = {1, 0, 1, 1, 1};
	bool B2[5] = {1, 0, 1, 0, 0};
	int C2[6] = {0};

	BinarySum(A2, B2, C2, 5);
	for(auto x: C2) {
		std::cout << x;
	}
}
