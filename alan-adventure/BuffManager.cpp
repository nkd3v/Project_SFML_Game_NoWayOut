#include "stdafx.h"
#include "BuffManager.h"

BuffManager::BuffManager(Entity& entity) :
  entity(entity)
{
  buffNames[SWIFT] = "Swift buff";
  buffNames[RAPID_FIRE] = "Rapid Fire Buff";
}

BuffManager::~BuffManager()
{
}

const std::vector<std::unique_ptr<Buff>>& BuffManager::getBuffs() const
{
  return buffs;
}

void BuffManager::createBuff(unsigned int buffType, float lifetimeMax, sf::Vector2f pos)
{
  for (const auto& buff : buffs)
  {
    if (buffNames[buffType] == buff->getName())
    {
      buff->reset();
      return;
    }
  }

  switch (buffType)
  {
  case SWIFT:
    buffs.push_back(std::make_unique<SwiftBuff>(lifetimeMax, entity));
    break;
  case RAPID_FIRE:
    buffs.push_back(std::make_unique<RapidFireBuff>(lifetimeMax, entity));
    break;
  case WARP:
    buffs.push_back(std::make_unique<WarpEffect>(lifetimeMax, entity));
    break;
  case BLOOD_SPLAT:
    buffs.push_back(std::make_unique<BloodSplat>(lifetimeMax, entity, pos));
    break;
  }
}

void BuffManager::update()
{
  for (auto it = buffs.begin(); it != buffs.end();)
  {
    (*it)->update();

    if ((*it)->endOfLife())
      it = buffs.erase(it);
    else
      it++;
  }
}

void BuffManager::render(sf::RenderTarget& target)
{
  for (auto it = buffs.begin(); it != buffs.end(); it++)
  {
    (*it)->render(target);
  }
}
