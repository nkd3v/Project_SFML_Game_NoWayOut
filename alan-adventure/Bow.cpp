#include "stdafx.h"
#include "Bow.h"

Bow::Bow()
{
  shootCooldown = .5f;
  defaultCooldown = .5f;
  rapidCooldown = .1f;
  rapidFireCountdown = 0.f;
  lastShootTime = .0f;
  firstAttack = false;

  shootArrowSound.setBuffer(am.getSoundBuffer("SHOOT_ARROW"));
  shootArrowSound.setVolume(10);
}

Bow::~Bow()
{
}

void Bow::setCooldown(float cooldown)
{
  shootCooldown = cooldown;
}

void Bow::activateRapidFire(float time)
{
  rapidFireCountdown = time;
}

void Bow::shoot(sf::Vector2f pos, float angle)
{
  if (canShoot())
  {
    bullets.emplace_back(std::make_unique<Bullet>(pos, 1000.f, angle));
    shootArrowSound.play();
  }
}

const std::vector<std::unique_ptr<Bullet>>& Bow::getBullets() const
{
  return bullets;
}

bool Bow::canShoot()
{
  lastShootTime = clock.getElapsedTime().asSeconds();

  if (rapidFireCountdown > .0f)
    shootCooldown = rapidCooldown;
  else
    shootCooldown = defaultCooldown;

  if (lastShootTime > shootCooldown || firstAttack)
  {
    firstAttack = false;
    lastShootTime = 0.0f;
    clock.restart();

    return true;
  }

  return false;
}

void Bow::update(const float& dt)
{
  rapidFireCountdown -= dt;
  if (rapidFireCountdown < 0.f)
    rapidFireCountdown = 0.f;

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

void Bow::render(sf::RenderTarget& target)
{
  for (auto& bullet : bullets)
    bullet->render(target);
}
