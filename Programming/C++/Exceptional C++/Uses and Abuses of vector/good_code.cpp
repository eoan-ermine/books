#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	std::vector<int> v;
	v.reserve(100);

// 	assert(v.capacity() >= 2); -- redundant

	v.push_back(0);
	v.push_back(1);

	std::copy(
		v.begin(), v.end(), std::ostream_iterator<int>(cout, "\n")
	);

	cout << v[0] << '\n';

	v[2] = 3;
	v[3] = 4;
//	...
	v[99] = 100;

	for(vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
		cout << *i << '\n';
	}
}
