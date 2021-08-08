#include <iostream>
#include <thread>
#include <atomic>

struct StdioManager {
	void write(const char* message) {
		std::cout << message << std::endl;
	}
};


int main() {
	StdioManager manager;
	std::atomic_ref<StdioManager> manager(manager);

	std::thread([&manager]() {
		for(int i = 0; i <= 10; ++i) {
			manager.write("Hello");
		}
	});
	std::thread([&manager]() {
		for(int i = 0; i <= 10; ++i) {
			manager.write("Bye");
		}
	});
}

// ALARM! SHIT!
