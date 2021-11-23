#pragma once

#include "Entity.h"

class Item
{
protected:
  sf::Sprite sprite;
  sf::Vector2f pos;
  sf::Texture texture;

public:
  Item(float x, float y);
  virtual ~Item();

  virtual void update(const float& dt);
  virtual void render(sf::RenderTarget& target);
};

