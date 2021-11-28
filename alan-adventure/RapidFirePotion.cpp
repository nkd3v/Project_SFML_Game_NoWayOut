#include "stdafx.h"
#include "RapidFirePotion.h"

RapidFirePotion::RapidFirePotion(float x, float y, sf::Texture& texture, Player& player, BuffManager* buffManager)
  : Item(x, y, texture, player, buffManager)
{
  sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
}

RapidFirePotion::~RapidFirePotion()
{
}

void RapidFirePotion::activate()
{
  buffManager->createBuff(RAPID_FIRE, 5.f);
}


