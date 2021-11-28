#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(sf::Vector2f pos, float speed, float angle, std::string texture)
  : speed(speed), angle(angle)
{
  initVariables();

  sprite.setTexture(am.getTexture(texture));
  sprite.setPosition(pos);
  sprite.setRotation(angle * 180.f / (float)M_PI);
}

Bullet::~Bullet()
{
}

void Bullet::initVariables()
{
  lifetime = 0.f;
  lifespan = 1.f;
  life = 1;
}

void Bullet::kill()
{
  life = 0;
}

bool Bullet::endofLife()
{
  lifetime = timer.getElapsedTime().asSeconds();
  return lifetime > lifespan || life == 0;
}

void Bullet::update(const float& dt)
{
  sprite.move(speed * cos(angle) * dt, speed * sin(angle) * dt);
}

void Bullet::render(sf::RenderTarget& target)
{
  target.draw(sprite);
}


