#include <iostream>
#include <vector>
#include <string>

#include <boost/any.hpp>

int maiin() {
	std::vector<boost::any> some_values;

	some_values.push_back(10);
	some_values.push_back("hello there!");
	some_values.push_back(std::string("Wow!"));

	std::string& s = boost::any_cast<std::string&>(some_values.back());
	s += " That is great!";
	std::cout << s;
}
