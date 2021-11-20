#include "stdafx.h"
#include "State.h"

State::State(sf::RenderWindow* window)
  : window(window)
{
  quit = false;
  paused = false;
  keytime = 0.f;
  keytimeMax = 10.f;
}

State::~State()
{
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

void State::updateMousePositions(sf::View* view)
{
  mousePosScreen = sf::Mouse::getPosition();
  mousePosWindow = sf::Mouse::getPosition(*window);

  if (view)
    window->setView(*view);

  mousePosView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

  window->setView(window->getDefaultView());
}

void State::updateKeytime(const float& dt)
{
  if (keytime < keytimeMax)
    keytime += 100.f * dt;
}