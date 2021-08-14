#include <cstring>
#include <utility>

class BadString {
public:
	BadString(const char* value) { data = new char[strlen(value) + 1]; strcpy(data, value); }
	~BadString() { delete[] data; }

	BadString& operator=(const BadString& rhs);
private:
	char* data;
};

BadString& BadString::operator=(const BadString& rhs) {
	delete[] data;
	data = new char[strlen(rhs.data) + 1];
	strcpy(data, rhs.data);
	return *this;
};

class GoodString {
public:
	GoodString(const char* value) { data = new char[strlen(value) + 1]; strcpy(data, value); }
	~GoodString() { delete[] data; }

	GoodString& operator=(const GoodString& rhs);
private:
	char* data;
};

GoodString& GoodString::operator=(const GoodString& rhs) {
	if(this == std::addressof(rhs)) {
		return *this;
	}

	delete[] data;
	data = new char[strlen(rhs.data) + 1];
	strcpy(data, rhs.data);
	return *this;
};

int main() {
	BadString a = "Hello";
	a = a; // SHIT!

	GoodString b = "Hi";
	b = b; // GOOD
}