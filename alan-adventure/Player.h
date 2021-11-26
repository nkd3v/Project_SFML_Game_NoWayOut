#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Weapon.h"
#include "Bow.h"

class Entity;

class Player :
	public Entity
{
private:

	sf::Clock damageTimer;
	sf::Int32 damageTimerMax;

	void initVariables();
	void initAnimations();

public:
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();

	AttributeComponent* getAttributeComponent();

	Bow* weapon;
	Bow* getWeapon();

	const bool getDamageTimer();

	void attack(sf::Vector2f mousePos);

	void loseHP(const int hp);
	void gainHP(const int hp);

	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif