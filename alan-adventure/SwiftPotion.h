#pragma once

#include "Item.h"

class SwiftPotion
  : public Item
{
private:

public:
  SwiftPotion(float x, float y, sf::Texture &texture, Entity &player);
  ~SwiftPotion();

  void activate();
};

