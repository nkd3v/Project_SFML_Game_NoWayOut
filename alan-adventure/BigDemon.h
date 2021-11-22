#ifndef BIG_DEMON_H
#define BIG_DEMON_H

#include "Enemy.h"

class BigDemon :
	public Enemy
{
private:
	void initVariables();
	void initAnimations();
	void initAI();
	void initGUI();

	sf::RectangleShape hpBar;

	AIFollow* follow;

public:
	BigDemon(float x, float y, sf::Texture& texture_sheet, Entity& player);
	virtual ~BigDemon();

	//Functions
	void updateAnimation(const float& dt);
	void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

	void render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox);
};

#endif // !BIG_DEMON_H