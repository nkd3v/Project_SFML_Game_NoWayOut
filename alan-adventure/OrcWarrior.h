#ifndef ORC_WARRIOR_H
#define ORC_WARRIOR_H

#include "Enemy.h"

class OrcWarrior :
	public Enemy
{
private:
	void initVariables();
	void initAnimations();

	sf::RectangleShape hpBar;

	AI* follow;

public:
	OrcWarrior(float x, float y, sf::Texture& texture_sheet, Entity& player);
	virtual ~OrcWarrior();

	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif