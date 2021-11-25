#ifndef SKELET_H
#define SKELET_H

#include "Enemy.h"

class Skelet :
	public Enemy
{
private:
	void initVariables();
	void initAnimations();

	AI* follow;

public:
	Skelet(float x, float y, sf::Texture& texture_sheet, Entity& player);
	virtual ~Skelet();

	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif