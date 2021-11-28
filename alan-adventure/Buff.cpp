#include "stdafx.h"
#include "Buff.h"

Buff::Buff(float lifetimeMax, Entity& entity) :
  lifetime(0.f), lifetimeMax(lifetimeMax), entity(entity)
{
}

Buff::~Buff()
{
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

void Buff::reset(float newLifetimeMax)
{
  lifetime = 0.f;
  if (newLifetimeMax != 0.f)
    lifetimeMax = newLifetimeMax;
}
