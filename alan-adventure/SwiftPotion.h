#pragma once

#include "Item.h"

class SwiftPotion
  : public Item
{
private:

public:
  SwiftPotion(float x, float y, sf::Texture &texture, Player &player);
  ~SwiftPotion();

  void activate();
};

