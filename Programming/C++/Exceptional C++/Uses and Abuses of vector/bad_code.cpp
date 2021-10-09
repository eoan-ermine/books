#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main() {
	vector<int> v;

	v.reserve(2);
	assert(v.capacity() == 2);
	v[0] = 1;
	v[1] = 1;
	for(vector<int>::iterator i = v.begin(); i < v.end(); i++) {
		cout << *i << endl;
	}

	cout << v[0];
	v.reserve(100);
	assert(v.capacity() == 100);
	cout << v[0];

	v[2] = 3;
	v[3] = 4;
//	...
	v[9] = 100;

	for(vector<int>::iterator i = v.begin(); i < v.end(); i++) {
		cout << *i << endl;
	}
}
