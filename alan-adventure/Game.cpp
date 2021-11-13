#include "Game.h"

void Game::initWindow()
{
  window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Alan's Adventure");
  window->setFramerateLimit(120);
  window->setVerticalSyncEnabled(false);
}

void Game::initStates()
{
  states.emplace(std::make_unique<GameState>(window));
}

Game::Game()
{
  initWindow();
  initStates();
}

Game::~Game()
{
  delete window;

  while (!states.empty())
  {
    states.pop();
  }
}

void Game::update()
{
  updateSFMLEvents();

  if (!states.empty())
    states.top()->update(dt);
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

  if (!states.empty())
    states.top()->render(window);

  window->display();
}
