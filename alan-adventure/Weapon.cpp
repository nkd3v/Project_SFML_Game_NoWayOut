#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon()
{
  shootCooldown = .5f;
  lastShootTime = .0f;
  firstAttack = false;

  if (!shootArrowBuffer.loadFromFile("assets/Sounds/shoot-arrow.wav"))
    throw "Error: Could not load shoot arrow sound.";
}

Weapon::~Weapon()
{
}

void Weapon::setCooldown(float cooldown)
{
  shootCooldown = cooldown;
}

void Weapon::shoot(sf::Vector2f pos, float angle)
{
  if (canShoot())
  {
    bullets.emplace_back(std::make_unique<Bullet>(pos, 1000.f, angle));
    shootArrowSound.play();
  }
}

const std::vector<std::unique_ptr<Bullet>>& Weapon::getBullets() const
{
  return bullets;
}

bool Weapon::canShoot()
{
  lastShootTime = clock.getElapsedTime().asSeconds();

  if (lastShootTime > shootCooldown || firstAttack)
  {
    firstAttack = false;
    lastShootTime = 0.0f;
    clock.restart();

    return true;
  }

  return false;
}

void Weapon::update(const float& dt)
{
  for (auto it = bullets.begin(); it != bullets.end();)
  {
    if ((*it)->endofLife())
      it = bullets.erase(it);
    else
      it++;
  }

  for (auto& bullet : bullets)
    bullet->update(dt);
}

void Weapon::render(sf::RenderTarget& target)
{
  for (auto& bullet : bullets)
    bullet->render(target);
}
