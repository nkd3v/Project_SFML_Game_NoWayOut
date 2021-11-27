#include "stdafx.h"
#include "VectorMath.h"

const float vectorDistance(const float x1, const float y1, const float x2, const float y2)
{
  const float dx = x2 - x1;
  const float dy = y2 - y1;

  return sqrtf(powf(dx, 2) + powf(dy, 2));
}

const float vectorDistance(sf::Vector2f vec1, sf::Vector2f vec2)
{
  const sf::Vector2f dVec = vec2 - vec1;

  return sqrtf(powf(dVec.x, 2) + powf(dVec.y, 2));
}

const float vectorAngle(sf::Vector2f vec1, sf::Vector2f vec2)
{
  auto d(vec2 - vec1);
  return atan2f(d.y, d.x);
}
