#include <string>
#include <iostream>


#include "commandline.h"

traffic::Commandline::Commandline()
:
	_desc("Traffic query server options")
{
	_desc.add_options()
		("help,h", "Print help message.")
		;
}

bool traffic::Commandline::parse(int argc, char const *argv[])
{
	po::variables_map _vm;
	po::store(po::parse_command_line(argc, argv, _desc), _vm);
	po::notify(_vm);

	if (_vm.count("help")) {
		std::cout << _desc << std::endl;
		return false;
	}
	return true;
}
