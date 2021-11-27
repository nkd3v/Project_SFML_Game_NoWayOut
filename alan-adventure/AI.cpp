#include "stdafx.h"
#include "AI.h"

AI::AI(Entity& self, Entity& entity)
  : self(self), entity(entity)
{
}

AI::~AI()
{
}

void AI::update(const float& dt)
{
  sf::Vector2f moveVec(entity.getPosition() - self.getPosition());

  float vecLength = sqrtf(powf(moveVec.x, 2) + powf(moveVec.y, 2));

  moveVec /= vecLength;

  if ((self.getPosition().x != entity.getPosition().x)
    && std::abs(vecLength) < 500.f
    && std::abs(vecLength) > 5.f)
    self.move(moveVec.x, moveVec.y, dt);
}
