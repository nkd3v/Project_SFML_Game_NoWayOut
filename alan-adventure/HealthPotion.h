#pragma once

#include "Item.h"

class HealthPotion
  : public Item
{
private:

public:
  HealthPotion(float x, float y, sf::Texture &texture, Entity &player);
  ~HealthPotion();

  void activate();
};

