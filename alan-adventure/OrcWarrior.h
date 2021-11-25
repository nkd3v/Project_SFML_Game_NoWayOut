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

	AIFollow* follow;

public:
	OrcWarrior(float x, float y, sf::Texture& texture_sheet, Entity& player);
	virtual ~OrcWarrior();

	void updateAnimation(const float& dt);
	void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

	void render(sf::RenderTarget& target);
};

#endif