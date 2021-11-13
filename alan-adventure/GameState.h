#pragma once

#include <vector>

#include "State.h"
#include "ScoreBoard.h"
#include "Player.h"
#include "Enemy.h"

class GameState :
    public State
{
private:
  Player player;

  void initVariables();

public:
  GameState(sf::RenderWindow* window);
  virtual ~GameState();

  void render(sf::RenderTarget* target = nullptr);
  void update(const float& dt);
};

