#include "stdafx.h"
#include "FullHealthPotion.h"

FullHealthPotion::FullHealthPotion(float x, float y, sf::Texture& texture, Player& player)
  : Item(x, y, texture, player)
{
  sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
}

FullHealthPotion::~FullHealthPotion()
{
}

void FullHealthPotion::activate()
{
  player.getAttributeComponent()->gainHP(8);
}


