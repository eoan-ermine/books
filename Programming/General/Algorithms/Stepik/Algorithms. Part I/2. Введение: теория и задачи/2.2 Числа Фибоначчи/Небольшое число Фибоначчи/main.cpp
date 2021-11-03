#include <cassert>
#include <iostream>

class Fibonacci final {
 public:
  static int get(int n) {
    assert(n >= 0);

	if(n <= 1) return n;

    int a = 0;
	int b = 1;
	int result = 0;

	for(int i = 1; i < n; ++i) {
		result = a + b;
		a = b;
		b = result;
	}

    return result;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  return 0;
}
