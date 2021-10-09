#include <vector>
#include <iostream>

template<class T>
class Array {
private:
	std::vector<T> data;

	size_t size;
	int lBound, hBound;
public:
	Array(int lowBound, int highBound)
		: size(highBound - lowBound + 1),
		  lBound(lowBound), hBound(highBound), data(size) {
		std::cout << data.size() << '\n';		  
	}
};


// ^ Shit, shit, shit! 

int main() {
	Array<int> array{10, 20}; // CORE DUMPED!
}