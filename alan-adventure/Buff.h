#pragma once

#include "Entity.h"

class Buff
{
private:

protected:
  std::string name;

  float lifetime;
  float lifetimeMax;

  virtual void updateLifetime();

  Entity& entity;

public:
  Buff(float lifetimeMax, Entity& entity);
  virtual ~Buff();

  virtual const std::string& getName() const;

  virtual bool endOfLife();
  virtual void update();
  virtual void render(sf::RenderTarget& target);
  virtual void reset(float newLifetimeMax = 0.f);
};

