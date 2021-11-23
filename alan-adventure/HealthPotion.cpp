#include "stdafx.h"
#include "HealthPotion.h"

HealthPotion::HealthPotion(float x, float y)
  : Item(x, y)
{
  if (!texture.loadFromFile("assets/Items/potions.png"))
    throw "Error: Could not load potions texture";

  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

HealthPotion::~HealthPotion()
{
}
