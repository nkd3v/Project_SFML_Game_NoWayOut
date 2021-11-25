#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "AIFollow.h"

class Enemy :
	public Entity
{
protected:
	unsigned gainExp;
	sf::Clock damageTimer;
	sf::Int32 damageTimerMax;

	virtual void initVariables() = 0;
	virtual void initAnimations() = 0;

public:
	Enemy();
	virtual ~Enemy();

	const unsigned& getGainExp() const;
	const bool getDamageTimerDone() const;

	void resetDamageTimer();

	virtual void loseHP(const int hp);
	virtual const bool isDead() const;

	virtual const AttributeComponent* getAttributeComp() const;

	virtual void updateAnimation(const float& dt) = 0;

	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

#endif //!ENEMY_H
