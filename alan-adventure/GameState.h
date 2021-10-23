#pragma once

#include "State.h"

class GameState :
    public State
{
private:

public:
  GameState(sf::RenderWindow* window);
  virtual ~GameState();

  void checkForQuit();

  void render(sf::RenderTarget* target = nullptr);
  void update(const float& dt);
};

