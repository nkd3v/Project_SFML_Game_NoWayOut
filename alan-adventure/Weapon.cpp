#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(float cooldown) :
  cooldown(cooldown),
  cooldownMax(cooldown)
{
}

Weapon::~Weapon()
{
}

bool Weapon::canShoot(const float& dt)
{
  cooldown -= dt;
  if (cooldown <= 0.f)
  {
    cooldown = cooldownMax;
    return true;
  }

  return false;
}