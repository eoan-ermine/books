#include <thread>
#include <iostream>

int main() {
	std::jthread thread([]{ std::cout << "Joinable std::jthread" << '\n'; });
	std::cout << "thread.joinable(): " << thread.joinable() << "\n\n";
}
