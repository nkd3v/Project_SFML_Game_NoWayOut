#include "Enemy.h"

Enemy::Enemy(
  sf::Texture *texture,
  sf::Vector2u imageCount,
  float switchTime,
  float speed,
  sf::Vector2f size,
  sf::Vector2f position
) : anim(texture, imageCount, switchTime)
{
  body.setSize(size);
  body.setOrigin(size / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

Enemy::~Enemy()
{

}

void Enemy::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}