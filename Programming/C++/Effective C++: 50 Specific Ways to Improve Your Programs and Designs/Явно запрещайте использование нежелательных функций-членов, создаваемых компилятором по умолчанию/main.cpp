// For example, we want our generic array class
// to behave like normal arrays

template<class T>
class Array {
public:
	Array(int size, T fill) { }
	Array& operator=(const Array& rhs) = delete;
	// ...
};

template<class T>
Array(int, T) -> Array<T>;

int main() {
	Array arr1(0, 'a');
	Array arr2(0, 1);

	arr1 = arr2; // error as

	double values1[10];
	double values2[10];

	values1 = values2; // error
}