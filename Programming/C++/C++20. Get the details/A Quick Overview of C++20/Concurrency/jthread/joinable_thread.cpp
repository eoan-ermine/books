#include <thread>
#include <iostream>

int main() {
	std::thread thread([]{std::cout << "Joinable std::thread" << '\n'; });
	std::cout << "thread.joinable(): " << thread.joinable() << "\n\n";
}

