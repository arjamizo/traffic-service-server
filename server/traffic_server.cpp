#include <iostream>

#include <zmq.hpp>


#include "traffic_server.h"


bool traffic::TrafficServer::bind(std::string const &address)
{
	try {
		_incomming->bind(address.c_str());
	} catch (zmq::error_t const & e) {
		std::cerr << "cannot bind to: '"
			  << address << "': "
		          << e.what() << std::endl;
		return false;
	}
	return true;
}


void traffic::TrafficServer::run()
{
	try {
		zmq::proxy(*_incomming, *_workers, NULL);
	} catch (zmq::error_t const &e) {
		std::cerr << "Cannot proxy between incomming and workers:"
			  << e.what() << std::endl;
	}
}


traffic::TrafficServer::TrafficServer()
:
	_context(new zmq::context_t(1)),
	_incomming(new zmq::socket_t(*_context, ZMQ_ROUTER)),
	_workers(new zmq::socket_t(*_context, ZMQ_DEALER))
{
	_workers->bind(WORKER_PORT);
}


traffic::TrafficServer::~TrafficServer() { }
