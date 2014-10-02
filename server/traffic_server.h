#ifndef __SERVER__TRAFFIC_SERVER_H__
#define __SERVER__TRAFFIC_SERVER_H__

#include <memory>
#include <string>


#define WORKER_PORT "inproc://workers"


namespace zmq {
	class context_t;
	class socket_t;
}


namespace traffic {

class TrafficServer
{
private:
	std::shared_ptr<zmq::context_t> _context;
	std::shared_ptr<zmq::socket_t> _incomming;
	std::shared_ptr<zmq::socket_t> _workers;

	TrafficServer(TrafficServer const &) = delete;
	TrafficServer& operator= (TrafficServer const &) = delete;

public:
	bool bind(std::string const &address);

	void run();

	TrafficServer();
	~TrafficServer();
};

}

#endif
