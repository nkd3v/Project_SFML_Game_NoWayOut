#include "stdafx.h"
#include "BloodSplat.h"

BloodSplat::BloodSplat(float lifetimeMax, Entity& entity, sf::Vector2f pos)
  : Buff(lifetimeMax, entity)
{
  name = "Blood splat";

  sprite.setPosition(pos);
  sprite.setTexture(am.getTexture("BLOOD_SPLAT"));
}

BloodSplat::~BloodSplat()
{
}

void BloodSplat::render(sf::RenderTarget& target)
{
  target.draw(sprite);
}
