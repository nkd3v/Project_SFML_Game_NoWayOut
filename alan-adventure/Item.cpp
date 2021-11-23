#include "stdafx.h"
#include "Item.h"

Item::Item(float x, float y, sf::Texture& texture, Entity& player)
  : pos(sf::Vector2f(x, y)), player(player)
{
  sprite.setPosition(pos.x, pos.y);
  sprite.setTexture(texture);
}

Item::~Item()
{
}

const sf::FloatRect& Item::getGlobalBounds() const
{
  return sprite.getGlobalBounds();
}

void Item::update(const float& dt)
{
  sprite.setPosition(pos.x, pos.y + sin(dt));
}

void Item::render(sf::RenderTarget& target)
{
  target.draw(sprite);
}
