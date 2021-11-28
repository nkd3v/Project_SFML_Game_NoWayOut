#include "stdafx.h"
#include "BuffManager.h"

BuffManager::BuffManager(Entity& entity) :
  entity(entity)
{
  buffNames[SWIFT] = "Swift buff";
}

BuffManager::~BuffManager()
{
}

void BuffManager::createBuff(unsigned int buffType, float lifetimeMax)
{
  using namespace std::string_literals;

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
