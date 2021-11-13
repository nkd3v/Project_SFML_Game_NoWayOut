#pragma once

#include "State.h"

class MainMenuState :
    public State
{
private:

public:
  MainMenuState(sf::RenderWindow* window);
  virtual ~MainMenuState();

  void update(const float& dt);
  void render(sf::RenderTarget* target);
};

