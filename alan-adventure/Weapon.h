#pragma once

#include "Entity.h"

class Weapon :
    public Entity
{
private:

protected:
  Entity& entity;

  float cooldown;
  float cooldownMax;

  virtual bool canShoot();
  virtual void updateCooldown();

public:
  Weapon(float cooldown, Entity& entity);
  ~Weapon();

  virtual const float& getCooldown() const;

  virtual void shoot(const sf::Vector2f& pos, float angle) = 0;
  virtual void update(const float& dt);
  virtual void render(sf::RenderTarget& target);
};

