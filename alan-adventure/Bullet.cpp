#include "Bullet.h"
#include <iostream>

Bullet::Bullet(sf::Texture &texture, sf::Vector2f pos, float speed, float angle)
  : mPos(pos), mSpeed(speed), mAngle(angle)
{
  mBody.setTexture(texture);
  mBody.setPosition(mPos);
  mBody.setTextureRect(sf::IntRect(0, 0, 8, 8));
  mBody.scale(2.0f, 2.0f);
}

void Bullet::Update(float deltaTime)
{
  std::cout << mAngle << '\n';
  mBody.move(mSpeed * cos(mAngle) * deltaTime, -mSpeed * sin(mAngle) * deltaTime);
}

void Bullet::Draw(sf::RenderTarget& target)
{
  //sf::Texture bulletTexture;
  //bulletTexture.loadFromFile("assets/bullet.png");
  //sf::Sprite test(bulletTexture);
  //test.setPosition({ 765.0f, 408.0f });
  //test.setTextureRect({ 0, 0, 32, 32 });
  //test.scale({ 4, 4 });
  //target.draw(test);
  target.draw(mBody);
}


