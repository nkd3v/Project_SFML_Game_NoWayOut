#pragma once

#include "Item.h"

class InvisiblePotion
  : public Item
{
private:

public:
  InvisiblePotion(float x, float y, sf::Texture &texture, Player &player);
  ~InvisiblePotion();

  void activate();
};

