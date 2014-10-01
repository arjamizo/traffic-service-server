#include <iostream>

#include "commandline.h"


int main(int argc, const char * argv[])
{
	std::cout << "Hi, I'm the traffic service" << std::endl;

	traffic::Commandline cmd;
	if (! cmd.parse(argc, argv)) {
		return 1;
	}

	return 0;
}
