#include "stdafx.h"
#include "AIEvade.h"

AIEvade::AIEvade(Entity& self, Entity& entity)
  : self(self), entity(entity)
{
  timeWarp = 0.f;
  timeWarpMin = 2.f;
  timeWarpMax = 4.f;
  timeWarpNext = 2.f;

  timeChangeDir = 3.f;
  timeChangeDirMin = .5f;
  timeChangeDirMax = 3.f;
  timeChangeDirNext = 1.5f;
}

AIEvade::~AIEvade()
{
}

bool AIEvade::canWarp()
{
  return timeWarp + Time.deltaTime >= timeWarpNext;
}

void AIEvade::updateDir(const float& dt)
{
  timeChangeDir += dt;
  if (timeChangeDir >= timeChangeDirNext)
  {
    moveVec = sf::Vector2f(
      (0.5f + (rand() % 50) / 50.f) * (rand() % 2 ? -1 : 1),
      (0.5f + (rand() % 50) / 50.f) * (rand() % 2 ? -1 : 1)
    );
    timeChangeDir = 0.f;
    timeChangeDirNext = timeChangeDirMin + rand() % static_cast<int>(timeChangeDirMax - timeChangeDirMin);
  }
}

void AIEvade::updateWarp(const float& dt)
{
  timeWarp += dt;
  if (timeWarp >= timeWarpNext)
  {
    self.setPosition(65.f + rand() % 510, 115.f + rand() % 385);
    timeWarp = 0.f;
    timeWarpNext = timeWarpMin + rand() % static_cast<int>(timeWarpMax - timeWarpMin);
  }
}

void AIEvade::update(const float& dt)
{
  updateDir(dt);
  updateWarp(dt);

  self.move(moveVec.x, moveVec.y, dt);
}
