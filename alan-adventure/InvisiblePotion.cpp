#include "stdafx.h"
#include "InvisiblePotion.h"

InvisiblePotion::InvisiblePotion(float x, float y, sf::Texture& texture, Player& player)
  : Item(x, y, texture, player)
{
  sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
}

InvisiblePotion::~InvisiblePotion()
{
}

void InvisiblePotion::activate()
{
  player.getAttributeComponent()->gainHP(2);
}


