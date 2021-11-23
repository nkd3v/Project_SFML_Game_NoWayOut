#include "stdafx.h"
#include "Game.h"

void Game::initWindow()
{
  window = new sf::RenderWindow(sf::VideoMode(800, 800), "Alan's Adventure", sf::Style::Close);
  window->setFramerateLimit(120);
  window->setVerticalSyncEnabled(false);
}

void Game::initStates()
{
  states.emplace(std::make_unique<ScoreboardState>(window, states));
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
  if (!this->states.empty())
  {
    if (this->window->hasFocus())
    {
      this->states.top()->update(this->dt, window);

      if (this->states.top()->getQuit())
      {
        std::unique_ptr<State> newState;
        if (states.top()->getNewState() != NULL)
          newState = std::move(states.top()->getNewState());

        states.top()->endState();
        states.pop();

        states.push(std::move(newState));
      }
    }
  }
  else
  {
    window->close();
  }
}

void Game::updateDt()
{
  dt = dtClock.restart().asSeconds();
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
