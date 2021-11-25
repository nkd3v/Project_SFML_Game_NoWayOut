#ifndef BIG_DEMON_H
#define BIG_DEMON_H

#include "Enemy.h"

class BigDemon :
	public Enemy
{
private:
	void initVariables();
	void initAnimations();

	sf::RectangleShape hpBar;

	AIFollow* follow;

public:
	BigDemon(float x, float y, sf::Texture& texture_sheet, Entity& player);
	virtual ~BigDemon();

	//Functions
	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif // !BIG_DEMON_H