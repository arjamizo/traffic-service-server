#ifndef __SERVER__COMMANDLINE_H__
#define __SERVER__COMMANDLINE_H__

#include <boost/program_options.hpp>

namespace traffic {
namespace po = boost::program_options;


class Commandline {
private:
	po::options_description _desc;
	po::variables_map _vm;

	Commandline(Commandline const &) = delete;
	Commandline& operator=(Commandline const &) = delete;

public:
	Commandline();
	bool parse(int argc, char const *argv[]);
	~Commandline() { }
};

}

#endif
