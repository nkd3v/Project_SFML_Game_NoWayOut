#ifndef SKELET_H
#define SKELET_H

#include "Enemy.h"

class Skelet :
	public Enemy
{
private:
	void initVariables();
	void initAnimations();

	sf::RectangleShape hpBar;

	AIFollow* follow;

public:
	Skelet(float x, float y, sf::Texture& texture_sheet, Entity& player);
	virtual ~Skelet();

	void updateAnimation(const float& dt);
	void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

	void render(sf::RenderTarget& target);
};

#endif