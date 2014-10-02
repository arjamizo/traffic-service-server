#include <iostream>
#include <string>

#include "commandline.h"
#include "traffic_server.h"


int main(int argc, const char * argv[])
{
	std::cout << "Hi, I'm the traffic service" << std::endl;

	traffic::Commandline cmd;
	if (! cmd.parse(argc, argv)) {
		return 1;
	}

	traffic::TrafficServer server;

	for (std::string const &address : cmd.addresses()) {
		server.bind("tcp://" + address);
	}

	server.run();

	return 0;
}

