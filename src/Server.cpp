#include "Server.h"

void Server::init()
{
	if (listener == nullptr)
	{
		listener = std::make_unique<sf::TcpListener>();
	}

	if (listener->listen(53000) != sf::Socket::Status::Done)
	{
		std::cout << "Couldn't Bind Listener to port 53000" << std::endl;
	}
}

void Server::run()
{
	while (running)
	{
		sf::TcpSocket& c_sock = *connection.emplace_back(std::make_unique<sf::TcpSocket>());

		if (listener->accept(c_sock) != sf::Socket::Status::Done)
		{
			connection.pop_back();
			std::cout << "Connection failed on server side" << std::endl;
			continue;
		}

		std::cout << "Client Connected" << decltype.getRemotePort() << std::endl;
	}
}