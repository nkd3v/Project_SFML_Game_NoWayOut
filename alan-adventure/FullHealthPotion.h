#pragma once

#include "Item.h"

class FullHealthPotion
  : public Item
{
private:

public:
  FullHealthPotion(float x, float y, sf::Texture &texture, Player &player);
  ~FullHealthPotion();

  void activate();
};

