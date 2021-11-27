#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(float cooldown, Entity& entity) :
  cooldown(cooldown),
  cooldownMax(cooldown),
  entity(entity)
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

void Weapon::update(const float& dt)
{
  sprite.setPosition(entity.getCenter());
  updateCooldown();
}

void Weapon::render(sf::RenderTarget& target)
{
  target.draw(sprite);
}
