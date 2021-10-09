#include <iostream>

/* library1.h:

	const double LIB_VERSION = 1.204;
*/

/* library2.h:

	const int LIB_VERSION = 3;

*/

/*
	Don't write shit like this:
*/

const double sdnHOOK_VERSION = 2.0;
class sdnHandle { };
sdnHandle& sndGetHandle() {
	static sdnHandle handle;
	return handle;
}

// Write this:

namespace sdn {
	const double HOOK_VERSION = 2.0;
	class Handle { };
	Handle& getHandle() {
		static sdn::Handle handle;
		return handle;
	}
}

void f1() {
	using namespace sdn;
	std::cout << HOOK_VERSION;
	Handle h = getHandle();
}

void f2() {
	using sdn::HOOK_VERSION;
	std::cout << HOOK_VERSION;
//	Handle h = getHandle() -- Error
}

void f3() {
	std::cout << sdn::HOOK_VERSION;
//	double d = HOOK_VERSION; - Error
//	Handle h = getHandle() -- Error
}

namespace AcmeWindowSystem {
	using Handle = int;
}

void f() {
	using namespace sdn;
	using namespace AcmeWindowSystem;

//	Handle h -- Error
	sdn::Handle h1;	// OK
	AcmeWindowSystem::Handle h2; // OK
}

int main() { }