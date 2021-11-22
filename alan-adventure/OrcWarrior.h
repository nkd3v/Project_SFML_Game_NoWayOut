#ifndef ORC_WARRIOR_H
#define ORC_WARRIOR_H

#include "Enemy.h"

class OrcWarrior :
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
	OrcWarrior(float x, float y, sf::Texture& texture_sheet, Entity& player);
	virtual ~OrcWarrior();

	//Functions
	void updateAnimation(const float& dt);
	void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

	void render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox);
};

#endif // !ORC_WARRIOR_H