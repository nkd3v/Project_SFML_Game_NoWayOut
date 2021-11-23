#include "stdafx.h"
#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states)
  : State(window, states)
{

}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::updateInput(const float& dt)
{
}

void MainMenuState::update(const float& dt)
{

}

void MainMenuState::render(sf::RenderTarget* target = nullptr)
{
  target->clear(sf::Color::Red);
}