#pragma once

#include "Item.h"

class RapidFirePotion
  : public Item
{
private:

public:
  RapidFirePotion(float x, float y, sf::Texture &texture, Entity &player);
  ~RapidFirePotion();

  void activate();
};

