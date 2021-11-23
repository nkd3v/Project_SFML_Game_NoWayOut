#pragma once

#include "Player.h"
#include "Entity.h"

class Item
{
protected:
  sf::Sprite sprite;
  sf::Vector2f pos;
  sf::Texture texture;
  Entity& player;

public:
  Item(float x, float y, sf::Texture& texture, Entity& player);
  virtual ~Item();

  const sf::FloatRect& getGlobalBounds() const;

  virtual void activate() = 0;

  virtual void update(const float& dt);
  virtual void render(sf::RenderTarget& target);
};

