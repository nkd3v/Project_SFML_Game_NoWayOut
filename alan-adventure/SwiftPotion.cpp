#include "stdafx.h"
#include "SwiftPotion.h"

SwiftPotion::SwiftPotion(float x, float y, sf::Texture& texture, Entity& player)
  : Item(x, y, texture, player)
{
  sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
}

SwiftPotion::~SwiftPotion()
{
}

void SwiftPotion::activate()
{
  player.getAttributeComponent()->gainHP(2);
}


