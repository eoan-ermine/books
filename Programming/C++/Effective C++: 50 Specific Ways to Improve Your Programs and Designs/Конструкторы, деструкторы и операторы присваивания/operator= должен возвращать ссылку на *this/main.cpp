struct Bad {
	void operator=(const Bad& rhs) {
		// Do something
	}
};

struct Good {
	Good& operator=(const Good& rhs) {
		return *this; 
	}
};

int main() {
	Bad a, b, c;
	a = b = c; // Compile error

	Good d, e, f;
	d = e = f; // OK
}