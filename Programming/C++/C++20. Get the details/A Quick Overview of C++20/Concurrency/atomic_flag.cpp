#include <iostream>
#include <thread>
#include <atomic>

int main() {
    std::atomic_flag busy(false);
    
	std::thread hello([&busy]() {
		for(int i = 0; i <= 10; ++i) {
            busy.wait(true);
            
            busy.test_and_set();
			std::cout << "Hello" << std::endl;
            busy.clear();
            
			busy.notify_one();
		}
	});
	std::thread bye([&busy]() {
		for(int i = 0; i <= 10; ++i) {
            busy.wait(true);
            
            busy.test_and_set();
			std::cout << "Bye" << std::endl;
            busy.clear();

			busy.notify_one();
		}
	});
    
    hello.join();
    bye.join();
}

// Someshit
