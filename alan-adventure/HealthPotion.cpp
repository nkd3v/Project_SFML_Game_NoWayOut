#include "stdafx.h"
#include "HealthPotion.h"

HealthPotion::HealthPotion(float x, float y, sf::Texture& texture, Entity& player)
  : Item(x, y, texture, player)
{
  sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

HealthPotion::~HealthPotion()
{
}

void HealthPotion::activate()
{
  player.getAttributeComponent()->gainHP(2);
}


