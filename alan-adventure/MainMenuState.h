#pragma once

#include "States.h"

class MainMenuState :
    public State
{
private:

public:
  MainMenuState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states);
  virtual ~MainMenuState();

  void updateInput(const float& dt);
  void update(const float& dt, sf::RenderTarget* target);
  void render(sf::RenderTarget* target);
};

