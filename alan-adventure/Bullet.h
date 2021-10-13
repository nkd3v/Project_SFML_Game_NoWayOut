#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
public:
  Bullet(const sf::Texture &texture, sf::Vector2f pos, float speed, float angle);
  ~Bullet();

  void Update(float deltaTime);
  void Draw(sf::RenderTarget& target);
  bool EndOfLife();

private:
  sf::Sprite mBody;
  sf::Vector2f mPos;
  float mSpeed;
  float mAngle;
  float mLifeSpan;
  float mLifeTime{};
};

