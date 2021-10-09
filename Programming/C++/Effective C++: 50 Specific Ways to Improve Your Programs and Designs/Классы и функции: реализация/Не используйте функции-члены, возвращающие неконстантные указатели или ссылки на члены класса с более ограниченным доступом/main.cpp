class Address { };

class Person {
public:
	using VerificationFunctionT = void(Person::*)(void);
	Address& personAddress() {
		return address;
	}
	Address* personAddressPtr() {
		return &address;
	}
	// ^ SHIT! MAKES address public

	static VerificationFunctionT verificationFunction() {
		return &Person::verifyAddress;
	}
	// ^ SHIT FOR SAME REASON
private:
	Address address;
	void verifyAddress() { }
};

int main() {
	Person scott;

	Address& addr = scott.personAddress();
	Address* addrPtr = scott.personAddressPtr();	

	auto function = Person::verificationFunction();
	(scott.*function)();
}