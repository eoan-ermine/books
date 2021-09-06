#include <iostream>
#include <atomic>
#include <thread>

class Spinlock {
	std::atomic_flag flag;
public:
	void lock() {
		while(flag.test_and_set()) ;
	}
	void unlock() {
		flag.clear();
	}
};

Spinlock spin;

void workOnResource() {
	spin.lock();
	std::cout << "Work done" << std::endl;
	spin.unlock();
}

int main() {
	std::thread t(workOnResource);
	std::thread t2(workOnResource);

	t.join();
	t2.join();
}
