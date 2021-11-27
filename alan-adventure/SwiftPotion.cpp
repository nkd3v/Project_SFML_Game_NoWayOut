#include "stdafx.h"
#include "SwiftPotion.h"

SwiftPotion::SwiftPotion(float x, float y, sf::Texture& texture, Player& player, BuffManager* buffManager)
  : Item(x, y, texture, player, buffManager)
{
  sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
}

SwiftPotion::~SwiftPotion()
{
}

void SwiftPotion::activate()
{
  buffManager->createBuff(SWIFT, 3.f);
}


