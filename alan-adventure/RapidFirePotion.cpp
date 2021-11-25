#include "stdafx.h"
#include "RapidFirePotion.h"

RapidFirePotion::RapidFirePotion(float x, float y, sf::Texture& texture, Player& player)
  : Item(x, y, texture, player)
{
  sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
}

RapidFirePotion::~RapidFirePotion()
{
}

void RapidFirePotion::activate()
{
  player.getWeapon()->activateRapidFire(3);
}


