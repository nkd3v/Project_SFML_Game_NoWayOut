#include "stdafx.h"
#include "RapidFireBuff.h"

RapidFireBuff::RapidFireBuff(float lifetimeMax, Entity& entity) :
  Buff(lifetimeMax, entity)
{
  name = "Rapid Fire Buff";
  player = dynamic_cast<Player*>(&entity);

  saveDefault();
  activate();
}

RapidFireBuff::~RapidFireBuff()
{
  restoreDefault();
}

const std::string& RapidFireBuff::getName() const
{
  return name;
}

void RapidFireBuff::saveDefault()
{
  defaultCooldown = player->getWeapon()->getCooldown();
}

void RapidFireBuff::activate()
{
  player->getWeapon()->setCooldown(.1f);
}

void RapidFireBuff::restoreDefault()
{
  player->getWeapon()->setCooldown(defaultCooldown);
}