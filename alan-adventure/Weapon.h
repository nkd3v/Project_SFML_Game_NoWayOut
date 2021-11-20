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
	void update(float deltaTime);
	void draw(sf::RenderTarget& target);
	void ChangeCooldown(float delta) { m_ShootCooldown = 0.075; }
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

