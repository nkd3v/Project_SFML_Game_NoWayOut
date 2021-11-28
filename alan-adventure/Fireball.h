#pragma once

#include "Entity.h"

class Bullet
  : public Entity
{
private:
  sf::Texture bulletTexture;

  sf::Clock timer;

  float speed;
  float angle;
  float lifespan;
  float lifetime;

  int life;

public:
  Bullet(sf::Vector2f pos, float speed, float angle);
  ~Bullet();

  void initVariables();
  void initTexture();

  void kill();
  bool endofLife();

  void update(const float& dt);
  void render(sf::RenderTarget& target);
};

