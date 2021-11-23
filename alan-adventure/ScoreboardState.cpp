#include "stdafx.h"
#include "ScoreboardState.h"

ScoreboardState::ScoreboardState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states)
  : State(window, states)
{

}

ScoreboardState::~ScoreboardState()
{
}

void ScoreboardState::updateInput(const float& dt)
{
}

void ScoreboardState::update(const float& dt)
{

}

void ScoreboardState::render(sf::RenderTarget* target = nullptr)
{
  target->clear(sf::Color::Blue);
}