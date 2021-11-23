#include "stdafx.h"
#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states)
  : State(window, states)
{
  if (!font.loadFromFile("assets/Fonts/dpcomic.ttf"))
    throw("Error: Could not load font");

  initMenu();
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::initMenu()
{
  selectedOption = 0;
  maxOptions = 3;

  for (auto& elm : menu)
  {
    elm.setFont(font);
    elm.setCharacterSize(42);
  }

  menu[0].setPosition(20.f, 50.f);
  menu[1].setPosition(20.f, 125.f);
  menu[2].setPosition(20.f, 200.f);

  menu[0].setString("Play");
  menu[1].setString("Scoreboard");
  menu[2].setString("Quit");
}

void MainMenuState::updateMenu()
{
  for (int i = 0; i < maxOptions; i++)
  {
    if (i == selectedOption)
      menu[i].setFillColor(sf::Color::White);
    else
      menu[i].setFillColor(sf::Color::Black);
  }
}

void MainMenuState::updateInput(const float& dt)
{
  if (!getKeytime()) return;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
    if (selectedOption <= 1)
      ++selectedOption;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    if (selectedOption >= 1)
      --selectedOption;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
  {
    switch (selectedOption)
    {
      case 0:
      {
        newState = std::make_unique<GameState>(window, states);
        break;
      }

      case 1:
      {
        newState = std::make_unique<ScoreboardState>(window, states);
        break;
      }

      case 2:
      {
        break;
      }
    }
    quit = true;
  }
}

void MainMenuState::update(const float& dt, sf::RenderTarget* target)
{
  updateSFMLEvents(target);
  updateKeytime(dt);
  updateInput(dt);
  updateMenu();
}

void MainMenuState::render(sf::RenderTarget* target = nullptr)
{
  target->clear(sf::Color(58, 68, 102));

  for (int i = 0; i < maxOptions; i++)
  {
    target->draw(menu[i]);
  }
}