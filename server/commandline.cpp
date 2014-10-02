#include <iostream>

#include <boost/assert.hpp>

#include "commandline.h"


#define DEFAULT_CONNECTION "*:3444"


std::vector<std::string>
traffic::Commandline::addresses() const
{
	BOOST_ASSERT(_vm.count("bind") && "No address there to bind!");

	if (! _vm.count("bind"))
		return std::vector<std::string>(1, DEFAULT_CONNECTION);
	return _vm["bind"].as<std::vector<std::string> >();
}


bool traffic::Commandline::parse(int argc, char const *argv[])
{
	try {
		po::store(po::parse_command_line(argc, argv, _desc), _vm);
		po::notify(_vm);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return false;
	}

	if (_vm.count("help")) {
		std::cout << _desc << std::endl;
		return false;
	}

	return true;
}


traffic::Commandline::Commandline()
:
	_desc("Traffic query server options")
{
	_desc.add_options()
		("help,h", "Print help message.")
		("bind,b",
		 po::value<std::vector<std::string> >()
			->default_value(
				std::vector<std::string>(1,
					DEFAULT_CONNECTION),
				DEFAULT_CONNECTION)
			->composing(),
		 "address:port combinations to bind to")
		;
}
