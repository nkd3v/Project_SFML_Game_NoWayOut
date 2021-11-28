#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "Enemy.h"

class Necromancer :
	public Enemy
{
private:
	void initVariables();
	void initAnimations();

	AIEvade* follow;

public:
	Necromancer(float x, float y, sf::Texture& texture_sheet, Entity& player);
	virtual ~Necromancer();

	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif