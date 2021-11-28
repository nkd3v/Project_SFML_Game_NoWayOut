#include "stdafx.h"
#include "Buff.h"

Buff::Buff(float lifetimeMax, Entity& entity) :
  lifetime(0.f), lifetimeMax(lifetimeMax), entity(entity)
{
}

Buff::~Buff()
{
}

const std::string& Buff::getName() const
{
  return name;
}

bool Buff::endOfLife()
{
  return lifetime >= lifetimeMax;
}

void Buff::updateLifetime()
{
  lifetime += Time.deltaTime;
}

void Buff::update()
{
  updateLifetime();
}

void Buff::render(sf::RenderTarget& target)
{
}

void Buff::reset(float newLifetimeMax)
{
  lifetime = 0.f;
  if (newLifetimeMax != 0.f)
    lifetimeMax = newLifetimeMax;
}
