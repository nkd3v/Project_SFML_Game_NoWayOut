#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
  : State(window)
{
}

GameState::~GameState()
{
}

void GameState::checkForQuit()
{

}

void GameState::render(sf::RenderTarget* target)
{
}

void GameState::update(const float& dt)
{
  std::cout << "Hello from Game state!\n";
}
