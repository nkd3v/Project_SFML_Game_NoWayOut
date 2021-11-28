#pragma once

#include "Entity.h"
#include "SwiftBuff.h"
#include "RapidFireBuff.h"
#include "WarpEffect.h"
#include "BloodSplat.h"

enum BuffTypes { SWIFT, RAPID_FIRE, WARP, BLOOD_SPLAT };

class BuffManager
{
private:

  Entity& entity;

  std::vector<std::unique_ptr<Buff>> buffs;
  std::map<unsigned int, std::string> buffNames;

public:

  BuffManager(Entity& entity);
  ~BuffManager();

  const std::vector<std::unique_ptr<Buff>>& getBuffs() const;

  void createBuff(unsigned int buffType, float lifetimeMax, sf::Vector2f pos = sf::Vector2f(0, 0));
  void update();
  void render(sf::RenderTarget& target);
};

