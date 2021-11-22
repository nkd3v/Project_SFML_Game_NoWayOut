#pragma once

#include "Bullet.h"

class Weapon
{
private:
	float shootCooldown;
	float lastShootTime;
	bool firstAttack;

	sf::Clock clock;
	std::vector<std::unique_ptr<Bullet>> bullets;

	bool canShoot();

public:
	Weapon();
	~Weapon();

	const std::vector<std::unique_ptr<Bullet>>& getBullets() const;

	void setCooldown(float cooldown);
	void shoot(sf::Vector2f pos, float angle);

	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

