#pragma once

#include "BuffManager.h"
#include "Player.h"
#include "Entity.h"

class Item
{
protected:
  sf::Sprite sprite;
  sf::Vector2f pos;
  sf::Texture texture;
  Player& player;
  BuffManager* buffManager;

public:
  Item(float x, float y, sf::Texture& texture, Player& player, BuffManager* buffManager = nullptr);
  virtual ~Item();

  const sf::FloatRect& getGlobalBounds() const;

  virtual void activate() = 0;

  virtual void update(const float& dt);
  virtual void render(sf::RenderTarget& target);
};

