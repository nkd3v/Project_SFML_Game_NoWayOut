#include "stdafx.h"
#include "Bow.h"

Bow::Bow() :
  Weapon(.5f)
{
  defaultCooldown = .5f;
  rapidCooldown = .1f;
  rapidFireCountdown = 0.f;

  shootArrowSound.setBuffer(am.getSoundBuffer("SHOOT_ARROW"));
  shootArrowSound.setVolume(20);
}

Bow::~Bow()
{
}

const std::vector<std::unique_ptr<Bullet>>& Bow::getBullets() const
{
  return bullets;
}

void Bow::updateCooldown()
{
  rapidFireCountdown -= Time.deltaTime;
  if (rapidFireCountdown < 0.f)
    rapidFireCountdown = 0.f;

  if (rapidFireCountdown > 0.f)
    cooldownMax = rapidCooldown;
  else
    cooldownMax = defaultCooldown;

  Weapon::updateCooldown();
}

void Bow::activateRapidFire(float time)
{
  rapidFireCountdown = time;
}

void Bow::shoot(const sf::Vector2f& pos, float angle)
{
  if (canShoot())
  {
    bullets.emplace_back(std::make_unique<Bullet>(pos, 1000.f, angle));
    shootArrowSound.play();
  }
}

void Bow::update(const float& dt)
{
  updateCooldown();

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
