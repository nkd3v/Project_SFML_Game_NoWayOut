#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
public:
  Bullet(sf::Texture &texture, sf::Vector2f pos, float speed, float angle);

  void Update(float deltaTime);
  void Draw(sf::RenderTarget& target);

private:
  sf::Sprite mBody;
  sf::Vector2f mPos;
  float mSpeed;
  float mAngle;
};

