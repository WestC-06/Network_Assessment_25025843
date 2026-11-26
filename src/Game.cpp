#include "Game.h"
#include "Tile.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  
}

Game::~Game()
{
    
}

bool Game::init()
{
    game_state = MENU;

    board = std::make_shared<Board>(window);
    board->init();

    if (!OpenSans.openFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
    {
        std::cout << "No Font??" << std::endl;
    }

    Host.setString("Host Game");
    Host.setCharacterSize(36);
    Host.setFillColor(sf::Color::White);
    Host.setPosition({1000.0f, 120.0f});

    Join.setString("Join Game");
    Join.setCharacterSize(36);
    Join.setFillColor(sf::Color::White);
    Join.setPosition({1000.0f, 480.0f});

    return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
    window.draw(Host);
    window.draw(Join);

    board->render();    
}

void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
    board->mouseButtonPressed(event);

    if (game_state == MENU)
    {
        if (Host.getGlobalBounds().contains(sf::Vector2f(event->position)))
        {
            game_state = GAME;
            std::cout << "Creating Server" << std::endl;
            server = std::make_unique<Server>();
            server->init();
            server->run();
        }

        else if (Join.getGlobalBounds().contains(sf::Vector2f(event->position)))
        {
            game_state = GAME;
            std::cout << "Connecting" << std::endl;
            client = std::make_unique<Client>();
            client->connect();
        }
    }
}

void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
    board->mouseButtonReleased(event);    
}

void Game::keyPressed(const sf::Event::KeyPressed* event)
{

}

void Game::keyReleased(const sf::Event::KeyReleased* event)
{

}

void Game::mouseMoved(const sf::Event::MouseMoved* event)
{
    board->mouseMoved(event);
}