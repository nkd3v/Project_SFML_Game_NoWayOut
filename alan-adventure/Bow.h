#pragma once

#include "Bullet.h"

class Bow
{
private:
	float defaultCooldown;
	float rapidCooldown;
	float shootCooldown;
	float lastShootTime;
	bool firstAttack;

	sf::Clock clock;
	std::vector<std::unique_ptr<Bullet>> bullets;

	sf::SoundBuffer shootArrowBuffer;
	sf::Sound shootArrowSound;

	float rapidFireCountdown;

	bool canShoot();

public:
	Bow();
	~Bow();

	const std::vector<std::unique_ptr<Bullet>>& getBullets() const;

	void setCooldown(float cooldown);
	void activateRapidFire(float time);
	void shoot(sf::Vector2f pos, float angle);

	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

