#pragma once
#include "Weapon.h"
#include "Bullet.h"

class Bow :
	public Weapon
{
private:
	float defaultCooldown;
	float rapidCooldown;

	float rapidFireCountdown;

	std::vector<std::unique_ptr<Bullet>> bullets;

	sf::Sound shootArrowSound;

	void updateCooldown();

public:
	Bow(Entity& entity);
	~Bow();

	const std::vector<std::unique_ptr<Bullet>>& getBullets() const;

	void activateRapidFire(float time);
	void shoot(const sf::Vector2f& pos, float angle);

	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

