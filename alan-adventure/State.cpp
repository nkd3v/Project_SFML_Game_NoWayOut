#include "stdafx.h"
#include "State.h"

State::State(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states, int code)
  : window(window), states(states), code(code)
{
  newState = NULL;
  quit = false;
  paused = false;
  keytime = 0.f;
  keytimeMax = 10.f;
  pressed = false;
}

State::~State()
{
}

std::unique_ptr<State>& State::getNewState()
{
  return newState;
}

const bool State::getKeytime()
{
  if (this->keytime >= this->keytimeMax)
  {
    this->keytime = 0.f;
    return true;
  }

  return false;
}

void State::endState()
{
  quit = true;
}

void State::pauseState()
{
  paused = true;
}

void State::unpauseState()
{
  paused = false;
}

void State::updateSFMLEvents(sf::RenderTarget* target)
{
  sf::Event e;

  while (window->pollEvent(e))
  {
    if (e.type == sf::Event::Closed)
    {
      window->close();
    }
    if (e.type == sf::Event::KeyPressed)
    {
      if (e.key.code == sf::Keyboard::Escape)
      {
        window->close();
      }
    }
  }
}

void State::updateMousePositions(sf::View* view)
{
  mousePosScreen = sf::Mouse::getPosition();
  mousePosWindow = sf::Mouse::getPosition(*window);

  if (view)
    window->setView(*view);

  mousePosView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

  Input.mousePosScreen = mousePosScreen;
  Input.mousePosWindow = mousePosWindow;
  Input.mousePosCoords = mousePosView;

  window->setView(window->getDefaultView());
}

void State::updateKeytime(const float& dt)
{
  if (keytime < keytimeMax)
    keytime += 100.f * dt;
}