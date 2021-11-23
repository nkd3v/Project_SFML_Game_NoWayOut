#include "stdafx.h"
#include "Item.h"

Item::Item(float x, float y)
  : pos(sf::Vector2f(x, y))
{
  sprite.setPosition(pos.x, pos.y);
}

Item::~Item()
{
}

void Item::update(const float& dt)
{
  sprite.setPosition(pos.x, pos.y + sin(dt));
}

void Item::render(sf::RenderTarget& target)
{
  target.draw(sprite);
}
