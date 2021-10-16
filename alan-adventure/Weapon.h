#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Bullet.h"

class Weapon
{
public:
	Weapon() = default;
	Weapon(sf::Texture& weaponTexture, sf::Texture& bulletTexture, float shootCooldown);
	~Weapon();

	void Shoot(sf::Vector2f pos, float angle);
	void Update(float deltaTime);
	void Draw(sf::RenderTarget& target);
	std::vector<Bullet*>& GetBullets();

private:
	sf::Sprite m_SBody;
	sf::Sprite m_SBullet;
	float m_ShootCooldown{};
	float m_LastShootTime{};
	std::vector<Bullet*> bullets;

	sf::Clock clock;
	bool CanShoot();

	bool firstAttack = true;
};

