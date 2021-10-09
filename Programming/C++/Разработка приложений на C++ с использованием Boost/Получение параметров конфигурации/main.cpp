#include <boost/program_options.hpp>
#include <iostream>

namespace opt = boost::program_options;

int main(int argc, char* argv[]) {
	opt::options_description desc("All options");

	int oranges = 0;
	int apples = 0;

	desc.add_options()
		("apples,a", opt::value<int>(&apples)->default_value(10), "how many apples do you have")
		("oranges,o", opt::value<int>(&oranges)->required(), "how many oranges do you have")
		("name", opt::value<std::string>(), "your name")
		("help", "produce help message")
	;

	opt::variables_map vm;
	opt::store(opt::parse_command_line(argc, argv, desc), vm);

	try {
		opt::store(
			opt::parse_config_file<char>("apples_oranges.cfg", desc),
			vm
		);
	} catch (const opt::reading_file& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		opt::notify(vm);
	} catch (const opt::required_option& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 2;
	}

	if(vm.count("help")) {
		std::cout << desc << '\n';
		return 1;
	}

	std::cout << "Fruits count: "
		<< vm["apples"].as<int>() + vm["oranges"].as<int>()
		<< std::endl;
}
