#include <cassert>
#include <iostream>

class Fibonacci final {
 public:
  static int get_last_digit(int n) {
    assert(n >= 1);

    int a = 0;
    int b = 1;
    int result = 0;

    for(int i = 1; i < n; ++i) {
		result = (a + b) % 10;
		a = b;
		b = result;
	}

    return result;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get_last_digit(n) << std::endl;
  return 0;
}