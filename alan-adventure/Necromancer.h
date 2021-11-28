#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "Enemy.h"
#include "Player.h"
#include "Bow.h"
#include "BuffManager.h"

class Necromancer :
	public Enemy
{
private:
	void initVariables();
	void initAnimations();

	Entity& player;
	Bow* bow;
	AIEvade* follow;
	sf::Sound playerHitSound;

	std::unique_ptr<BuffManager> buffManager;

public:
	Necromancer(float x, float y, sf::Texture& texture_sheet, Entity& player);
	virtual ~Necromancer();

	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif