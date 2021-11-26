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

bool Weapon::canShoot()
{
  if (cooldown <= 0.f)
  {
    cooldown = cooldownMax;
    return true;
  }

  return false;
}

void Weapon::updateCooldown()
{
  cooldown -= Time.deltaTime;
  if (cooldown <= 0.f)
    cooldown = 0.f;
}
