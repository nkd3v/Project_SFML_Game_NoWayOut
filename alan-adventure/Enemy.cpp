#include "stdafx.h"
#include "Enemy.h"
#include <iostream>

Enemy::Enemy(
  sf::Texture* texture,
  sf::Vector2u imageCount,
  float switchTime,
  float speed,
  sf::Vector2f size,
  sf::Vector2f position
) : anim(texture, imageCount, switchTime)
  , mSpeed(speed)
{
  body.setSize(size);
  body.setOrigin(size / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);

  dieTexture.loadFromFile("assets/Enemy/spr_blob_big_death.png");
  dieAnim = Animation(&dieTexture, sf::Vector2u(4, 1), 0.25f);
}

Enemy::~Enemy()
{
  
}

void Enemy::draw(sf::RenderWindow& window)
{
  window.draw(body);
}

void Enemy::update(float deltaTime)
{
  if (isAlive)
    updateAlive(deltaTime);
  else
    updateDie(deltaTime);
}

void Enemy::SetTarget(sf::Transformable* target)
{
  mTargetRef = target;
}

void Enemy::kill()
{
  return;
  isAlive = false;
  body.setTexture(&dieTexture);
}

void Enemy::updateAlive(float deltaTime)
{
  sf::Vector2f movement{ 0, 0 };

  if (mTargetRef != nullptr)
  {
    sf::Vector2f delta = mTargetRef->getPosition() - body.getPosition();

    if (abs(delta.x) > 1.0f || abs(delta.y) > 1.0f)
    {
      float angle = atan2(delta.y, delta.x);
      movement = sf::Vector2f(mSpeed * cos(angle) * deltaTime, mSpeed * sin(angle) * deltaTime);
      body.move(movement);
    }
  }

  if (movement.x != 0 && movement.y != 0)
  {
    row = 1;

    if (movement.x > 0)
    {
      faceRight = true;
    }
    else if (movement.x < 0)
    {
      faceRight = false;
    }
  }
  else
  {
    row = 0;
  }

  anim.update(row, deltaTime, faceRight);
  body.setTextureRect(anim.uvRect);
}

void Enemy::updateDie(float deltaTime)
{
  std::cout << "Died\n";
  dieAnim.update(0, deltaTime, 0);
  body.setTextureRect(sf::IntRect(0, 0, 32, 32));
}
