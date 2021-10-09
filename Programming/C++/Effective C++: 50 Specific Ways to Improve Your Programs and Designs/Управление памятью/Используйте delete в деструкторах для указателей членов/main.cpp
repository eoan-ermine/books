class MyClass {
	int* very_important_memory;
public:
	MyClass() {
		very_important_memory = new int[1000];
	}
	~MyClass() {
		// bad: if there are no delete of very_importand memory
		// good:
		delete[] very_important_memory;
	}
};

int main() { }
