#pragma once

#include "Entity.h"

class Bullet
  : public Entity
{
private:
  sf::Clock timer;

  float speed;
  float angle;
  float lifespan;
  float lifetime;

  int life;

public:
  Bullet(sf::Vector2f pos, float speed, float angle, std::string texture = "BULLET");
  ~Bullet();

  void initVariables();

  void kill();
  bool endofLife();

  void update(const float& dt);
  void render(sf::RenderTarget& target);
};

