#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
public:
  Bullet(const sf::Texture &texture, sf::Vector2f pos, float speed, float angle, float lifeSpan = 1.0f);
  ~Bullet();

  void Update(float deltaTime);
  void Draw(sf::RenderTarget& target);
  bool EndOfLife();

  sf::Sprite& GetBody() { return mBody; }

private:
  sf::Sprite mBody;
  sf::Vector2f mPos;
  sf::Clock timer;
  float mSpeed;
  float mAngle;
  float mLifeSpan{};
  float mLifeTime{};
};

