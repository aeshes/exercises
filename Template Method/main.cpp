#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>


struct NetworkDevice
{
	void send(void * data, std::size_t size);
private:
	virtual void send_impl(void *data, std::size_t size);
	void log(std::string const& comment);
};

void NetworkDevice::send(void * data, std::size_t size)
{
	log("Sending data");
	send_impl(data, size);
	log("Data sent");
}

void NetworkDevice::log(std::string const& comment)
{
	std::cout << comment << std::endl;
}

void NetworkDevice::send_impl(void * data, std::size_t size)
{
	std::cout << "Sending..." << std::endl;
}

struct Router : NetworkDevice
{
private:
	void send_impl(void *data, std::size_t size) override
	{
		std::cout << "Router::send_impl" << std::endl;
	}
};

int main()
{
	Router router;
	router.send(0, 0);
}