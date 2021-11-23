#include "stdafx.h"
#include "EnterNameState.h"

EnterNameState::EnterNameState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states)
  : State(window, states)
{

}

EnterNameState::~EnterNameState()
{
}

void EnterNameState::updateSFMLEvents(sf::RenderTarget* target)
{
  sf::Event e;
  while (window->pollEvent(e))
  {
    if (e.type == sf::Event::Closed)
    {
      window->close();
    }
    else if (e.type == sf::Event::TextEntered)
    {
      nameTextBox.update(e.text.unicode);
    }
  }
}

void EnterNameState::updateInput(const float& dt)
{
}

void EnterNameState::update(const float& dt, sf::RenderTarget* target)
{

}

void EnterNameState::render(sf::RenderTarget* target = nullptr)
{
  target->clear(sf::Color::Red);
}