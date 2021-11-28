#pragma once

#include "Item.h"

class RapidFirePotion
  : public Item
{
private:

public:
  RapidFirePotion(float x, float y, sf::Texture &texture, Player &player, BuffManager* buffManager);
  ~RapidFirePotion();

  void activate();
};

