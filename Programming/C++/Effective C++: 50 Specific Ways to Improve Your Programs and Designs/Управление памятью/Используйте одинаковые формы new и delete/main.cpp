#include <string>

void shit() {
	std::string* stringArray = new std::string[100];
	delete stringArray; // Скорее всего 99 элементов не будут удалены
}

void good() {
	std::string* stringArray = new std::string[100];
	delete[] stringArray; // Все будет удалено
}

int main() { }
