#include "stdafx.h"
#include "SwiftBuff.h"

SwiftBuff::SwiftBuff(float lifetimeMax, Entity& entity) :
  Buff(lifetimeMax, entity)
{
  name = "Swift buff";

  saveDefault();
  activate();
}

SwiftBuff::~SwiftBuff()
{
  restoreDefault();
}

const std::string& SwiftBuff::getName() const
{
  return name;
}

void SwiftBuff::saveDefault()
{
  defaultVelocity = entity.getMovementComponent()->getMaxVelocity();
}

void SwiftBuff::activate()
{
  entity.getMovementComponent()->setMaxVelocity(defaultVelocity * 2.f);
}

void SwiftBuff::restoreDefault()
{
  entity.getMovementComponent()->setMaxVelocity(defaultVelocity);
}
