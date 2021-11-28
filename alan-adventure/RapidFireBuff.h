#pragma once

#include "Buff.h"
#include "Player.h"

class RapidFireBuff
  : public Buff
{
private:

  float defaultCooldown = 0.f;
  Player* player;

public:
  RapidFireBuff(float lifetimeMax, Entity& entity);
  virtual ~RapidFireBuff();

  const std::string& getName() const;

  void saveDefault();
  void activate();
  void restoreDefault();
};

