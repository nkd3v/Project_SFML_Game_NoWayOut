#pragma once

#include "Entity.h"
#include "Bow.h"

class Weapon :
    public Entity
{
private:

protected:
  float cooldown;
  float cooldownMax;

  virtual bool canShoot(const float& dt);

public:
  Weapon(float cooldown);
  ~Weapon();

  virtual void shoot(const sf::Vector2f& pos, const sf::Vector2f& mousePos) = 0;
};

