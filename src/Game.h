
#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Server.h"
#include "Client.h"

class Game
{
public:
	Game(sf::RenderWindow& window);
	~Game();
	bool init();
	void update(float dt);
	void render();
	void mouseButtonPressed(const sf::Event::MouseButtonPressed* event);
	void mouseButtonReleased(const sf::Event::MouseButtonReleased* event);
	void keyPressed(const sf::Event::KeyPressed* event);
	void keyReleased(const sf::Event::KeyReleased* event);
	void mouseMoved(const sf::Event::MouseMoved* event);

	std::unique_ptr<::Server> server;
	std::unique_ptr<::Client> client;

	enum State
	{
		MENU,
		GAME,
	};
	State game_state;


private:
	
	sf::RenderWindow& window;
	
	sf::Font OpenSans;
	sf::Text Host { OpenSans };
	sf::Text Join { OpenSans };

	std::shared_ptr<Board> board;

};

