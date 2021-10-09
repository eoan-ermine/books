#include <cstring>
#include <iostream>

class String {
public:
	String(const char* value) {
		char* buffer = new char[strlen(value) + 1];
		strcpy(buffer, value);
		this->data = buffer;
	}
	~String() {
		delete[] data;
	}
	/* Insecure shit:
	operator char*() const {
		return data;
	}
	*/
	/* Slow shit:
	operator char*() const {
		char* copy = new char[strlen(data) + 1];
		strcpy(copy, data);
		return copy;
	}
	*/
	// Correct:
	operator const char*() const {
		return data;
	}
private:
	char* data;
};

String someFamousAuthor() {
	switch (rand() % 3) {
	case 0:
		return "Margaret Mitchell";
	case 1:
		return "Stephen King";
	case 2:
		return "Scott Meyers";
	}
	return "";
}

int main() {
	/* That insecure shit insecure because of we can do
		const String B("Hello World");
		char* str = B;
		strcpy(str, "Hi Mom");
	*/

	const char* pc = someFamousAuthor();
	std::cout << pc; // SHIT!
}