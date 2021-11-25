#pragma once

#include "Enemy.h"

class AI
{
private:
  Entity& self;
  Entity& entity;

public:
  AI(Entity& self, Entity& entity);
  ~AI();

  void update(const float& dt);
};

