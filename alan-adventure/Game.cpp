#include "Game.h"

void Game::initVariables()
{
  window = new sf::RenderWindow(sf::VideoMode(800, 800), "Alan's Adventure");
}

Game::Game()
{
  initVariables();
}

Game::~Game()
{
  delete window;
}

void Game::update()
{
  updateSFMLEvents();
}

void Game::updateDt()
{
  dt = dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
  while (window->pollEvent(sfEvent))
  {
    if (sfEvent.type == sf::Event::Closed)
    {
      window->close();
    }
  }
}

void Game::run()
{
  while (window->isOpen())
  {
    updateDt();
    update();
    render();
  }
}

void Game::render()
{
  window->clear();
  window->display();
}
