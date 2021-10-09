#include <string>
#include <stdexcept>

using namespace std;

string encrypt(string password) {
	return password;
}

string encryptPassword(const string& password) {
	string encrypted;
	if(password.length() < 10) {
		throw logic_error("Password is too short");
	}

	encrypted = encrypt(password);
	return encrypted;
}
// ^ FUCKING SHIT. UNNECESARY DEFAULT CONSTRUCTOR


string encryptPasswordGood(const string& password) {
	// ...
	string encrypted = encrypt(password);
	return encrypted;
}
// ^ OK

int main() { }