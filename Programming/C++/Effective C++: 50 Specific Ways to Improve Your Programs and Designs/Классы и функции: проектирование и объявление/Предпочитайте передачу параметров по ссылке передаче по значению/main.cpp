#include <string>
#include <iostream>

class Person {
public:
	Person() { }
	~Person() { }
private:
	std::string name, address;
};

class Student: public Person {
public:
	Student() { }
	~Student() { }
private:
	std::string schoolName, schoolAddress;
};

Student returnStudent(Student s) { return s; }

class Window {
public:
	std::string name() const {
		return "Minesweeper";
	}
	virtual void display() const {
		std::cout << "Show Window\n";
	}
};

class WindowWithScrollBars: public Window {
public:
	virtual void display() const {
		std::cout << "Show WindowWithScrollBars\n";
	}
};

void greet_and_display_shit(const Window w) {
	std::cout << w.name() << '\n';
	w.display();
}

void greet_and_display_good(const Window& w) {
	std::cout << w.name() << '\n';
	w.display();
}


int main() {
	Student plato;
	returnStudent(plato);

	// Without copy ellision there are
	// 12 constructor calls and 12 destructor call, so
	// it's better to take and return references

	WindowWithScrollBars wwsb;
	greet_and_display_shit(wwsb);
	greet_and_display_good(wwsb);
}