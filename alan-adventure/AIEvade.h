#pragma once

#include "Enemy.h"

class AIEvade
{
private:
  Entity& self;
  Entity& entity;

  float timeWarp;
  float timeWarpMin;
  float timeWarpMax;
  float timeWarpNext;

  float timeChangeDir;
  float timeChangeDirMin;
  float timeChangeDirMax;
  float timeChangeDirNext;

  sf::Vector2f moveVec;

  void updateDir(const float& dt);
  void updateWarp(const float& dt);

public:
  AIEvade(Entity& self, Entity& entity);
  ~AIEvade();

  void update(const float& dt);
};

