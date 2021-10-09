#include <cstring>

class BadString {
public:
	BadString(const char* value);
	~BadString();
private:
	char* data;
};

BadString::BadString(const char* value) {
	if (value) {
		data = new char[strlen(value) + 1];
		strcpy(data, value);
	} else {
		data = new char[1];
		*data = '\0';
	}
}

inline BadString::~BadString() { delete[] data; }

class GoodString {
public:
	GoodString(const char* value);
	~GoodString();

	GoodString(const GoodString& other);
	GoodString& operator=(const GoodString& rhs);
private:
	char* data;
};

GoodString::GoodString(const char* value) {
	if (value) {
		data = new char[strlen(value) + 1];
		strcpy(data, value);
	} else {
		data = new char[1];
		*data = '\0';
	}
}

GoodString::GoodString(const GoodString& other) {
	strcpy(data, other.data);
}

GoodString& GoodString::operator=(const GoodString& rhs) {
	delete[] this->data;
	strcpy(this->data, rhs.data);
	return *this;
}

inline GoodString::~GoodString() { delete[] data; }

int main() {
	BadString myString{"Hello, cruel world!"};
	BadString anotherString{"Yeah, hello!"};

	myString = anotherString; // Memory leak

	GoodString goodString{"Hello, wonderful world!"};
	GoodString anotherGoodString{"Hello, wonderful man!"};

	goodString = anotherGoodString; // No leak
}
