#include <iostream>
#include <cstddef>

template<std::size_t N>
void rotate_matrix(int (&image)[N][N]) {
	int new_image[N][N];

	int column = N - 1;
	for(int i = 0; i != N; ++i) {
		int row = 0;
		for(int j = 0; j != N; ++j) {
			new_image[j][column] = image[i][j];
		}
		--column;
	}

	for(int i = 0; i != N; ++i) {
		for(int j = 0; j != N; ++j) {
			image[i][j] = new_image[i][j];
		}
	}
}

int main() {
	int a[3][3] = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8}
	};
	rotate_matrix<3>(a);

	for(int i = 0; i != 3; ++i) {
		for(int j = 0; j != 3; ++j) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}