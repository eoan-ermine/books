#include <concepts>
#include <iostream>
#include <forward_list>
#include <list>
#include <vector>

template<std::forward_iterator I>
void advance(I& iter, int n) { }

template<std::bidirectional_iterator I>
void advance(I& iter, int n) { }

template<std::random_access_iterator I>
void advance(I& iter, int n) { }

int main() {
	std::forward_list<int> fwd;
	auto fwdIt = fwd.begin();
	advance(fwdIt, 2);

	std::list<int> list;
	auto listIt = list.begin();
	advance(listIt, 2);

	std::vector<int> vec;
	auto vecIt = vec.begin();
	advance(vecIt, 2);
}
