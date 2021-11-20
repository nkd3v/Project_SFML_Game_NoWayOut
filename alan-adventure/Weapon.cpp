#include "stdafx.h"
#include "Weapon.h"
#include <memory>
#include <iostream>

Weapon::Weapon(sf::Texture& weaponTexture, sf::Texture& bulletTexture, float shootCooldown)
  : m_SBody(weaponTexture), m_SBullet(bulletTexture), m_ShootCooldown(shootCooldown)
{
  m_LastShootTime = m_ShootCooldown;
}

Weapon::~Weapon()
{
}

void Weapon::Shoot(sf::Vector2f pos, float angle)
{
  if (CanShoot())
  {
    bullets.emplace_back(new Bullet(*m_SBullet.getTexture(), pos, 1000.0f, angle));
  }
}

void Weapon::update(float deltaTime)
{
  for (auto itr = bullets.begin(); itr != bullets.end();)
  {
    if ((*itr)->EndOfLife())
    {
      delete (*itr);
      itr = bullets.erase(itr);
    }
    else
    {
      itr++;
    }
  }

  for (auto& bullet : bullets)
  {
    bullet->update(deltaTime);
  }
}

void Weapon::draw(sf::RenderTarget& target)
{
  for (auto& bullet : bullets)
  {
    bullet->draw(target);
  }
}

std::vector<Bullet*>& Weapon::GetBullets()
{
  return bullets;
}

bool Weapon::CanShoot()
{
  m_LastShootTime = clock.getElapsedTime().asSeconds();
  if (m_LastShootTime > m_ShootCooldown || firstAttack)
  {
    firstAttack = false;
    m_LastShootTime = 0.0f;
    clock.restart();
    return true;
  }

  return false;
}
