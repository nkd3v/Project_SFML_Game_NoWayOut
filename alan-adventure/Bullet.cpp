#define _USE_MATH_DEFINES

#include "Bullet.h"
#include <iostream>
#include <math.h>

Bullet::Bullet(const sf::Texture &texture, sf::Vector2f pos, float speed, float angle)
  : mPos(pos), mSpeed(speed), mAngle(angle)
{
  std::cout << "Created!\n";
  mBody.setTexture(texture);
  mBody.setPosition(mPos);
  mBody.setTextureRect(sf::IntRect(0, 0, 8, 8));
  mBody.scale(2.0f, 2.0f);
}

Bullet::~Bullet()
{
  std::cout << "Destroyed!\n";
}

void Bullet::Update(float deltaTime)
{
  mBody.move(mSpeed * cos(mAngle * M_PI / 180.0f) * deltaTime, -mSpeed * sin(mAngle * M_PI / 180.0f) * deltaTime);
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

bool Bullet::EndOfLife()
{
  return mLifeTime > mLifeSpan;
}


