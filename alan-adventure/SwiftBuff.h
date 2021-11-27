#pragma once

#include "Buff.h"

class SwiftBuff
  : public Buff
{
private:

  float defaultVelocity = 0.f;

public:
  SwiftBuff(float lifetimeMax, Entity& entity);
  virtual ~SwiftBuff();

  const std::string& getName() const;

  void saveDefault();
  void activate();
  void restoreDefault();
};

