#define _USE_MATH_DEFINES

#include "Bullet.h"
#include <iostream>
#include <math.h>

Bullet::Bullet(const sf::Texture &texture, sf::Vector2f pos, float speed, float angle, float lifeSpan)
  : mPos(pos), mSpeed(speed), mAngle(angle), mLifeSpan(lifeSpan)
{
  mBody.setTexture(texture);
  mBody.setPosition(mPos);
  mBody.setTextureRect(sf::IntRect(0, 0, 8, 8));
  mBody.scale(3.0f, 3.0f);
}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime)
{
  mBody.move(mSpeed * cos(mAngle * float(M_PI) / 180.0f) * deltaTime, -mSpeed * sin(mAngle * float(M_PI) / 180.0f) * deltaTime);
}

void Bullet::Draw(sf::RenderTarget& target)
{
  target.draw(mBody);
}

bool Bullet::EndOfLife()
{
  mLifeTime = timer.getElapsedTime().asSeconds();
  return mLifeTime > mLifeSpan;
}


