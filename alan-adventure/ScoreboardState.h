#pragma once

#include "State.h"

class ScoreboardState :
  public State
{
private:

public:
  ScoreboardState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states);
  virtual ~ScoreboardState();

  void updateInput(const float& dt);
  void update(const float& dt);
  void render(sf::RenderTarget* target);
};

