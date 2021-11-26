#pragma once

#include "Entity.h"

class Weapon :
    public Entity
{
private:

protected:
  float cooldown;
  float cooldownMax;

  virtual bool canShoot();
  virtual void updateCooldown();

public:
  Weapon(float cooldown);
  ~Weapon();

  virtual void shoot(const sf::Vector2f& pos, float angle) = 0;
};

