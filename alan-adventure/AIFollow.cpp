#include "stdafx.h"
#include "AIFollow.h"

AIFollow::AIFollow(Entity& self, Entity& entity)
  : AIOption(self, entity)
{
}

AIFollow::~AIFollow()
{
}

void AIFollow::update(const float& dt)
{
  sf::Vector2f moveVec(entity.getPosition() - self.getPosition());

  float vecLength = sqrt(pow(moveVec.x, 2) + pow(moveVec.y, 2));

  moveVec /= vecLength;

  if ((self.getPosition().x != entity.getPosition().x)
    && std::abs(vecLength) < 500.f
    && std::abs(vecLength) > 5.f)
    self.move(moveVec.x, moveVec.y, dt);
}
