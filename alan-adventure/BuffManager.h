#pragma once

#include "Entity.h"
#include "SwiftBuff.h"

enum BuffTypes { SWIFT };

class BuffManager
{
private:

  Entity& entity;

  std::vector<std::unique_ptr<Buff>> buffs;
  std::map<unsigned int, std::string> buffNames;

public:

  BuffManager(Entity& entity);
  ~BuffManager();

  void createBuff(unsigned int buffType, float lifetimeMax);
  void update();
};

