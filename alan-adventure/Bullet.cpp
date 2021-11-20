#include "stdafx.h"
#include "Bullet.h"
#include <iostream>
#include <math.h>

#define PI 3.14159265358979

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

void Bullet::update(float deltaTime)
{
  mBody.move(mSpeed * cos(mAngle * float(PI) / 180.0f) * deltaTime, -mSpeed * sin(mAngle * float(PI) / 180.0f) * deltaTime);
}

void Bullet::draw(sf::RenderTarget& target)
{
  target.draw(mBody);
}

bool Bullet::EndOfLife()
{
  mLifeTime = timer.getElapsedTime().asSeconds();
  return mLifeTime > mLifeSpan;
}


