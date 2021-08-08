#include <stop_token>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::literals::chrono_literals;

int main() {
	std::cout << std::endl;

	std::jthread nonInterruptible([]{
		int counter{0};
		while (counter < 10) {
			std::this_thread::sleep_for(0.2s);
			std::cerr << "nonInterruptible: " << counter << std::endl;
			++counter;
		}
	});

	std::jthread interruptible([](std::stop_token stoken) {
		int counter{0};
		while (counter < 10) {
			std::this_thread::sleep_for(0.2s);
			if (stoken.stop_requested()) return;
			std::cerr << "Interruptible: " << counter << std::endl;
			++counter;
		}
	});

	std::this_thread::sleep_for(1s);

	std::cerr << std::endl;
	std::cerr << "Main thread interrupts both jthreads" << std::endl;

	nonInterruptible.request_stop();
	interruptible.request_stop();

	std::cout << std::endl;
}
