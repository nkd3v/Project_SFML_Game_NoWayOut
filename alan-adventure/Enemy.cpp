#include "stdafx.h"
#include "Enemy.h"

void Enemy::initVariables()
{
	this->gainExp = 10;
	this->damageTimerMax = 1000;
}

void Enemy::initAnimations()
{

}

Enemy::Enemy()
{
	this->initVariables();
	this->initAnimations();
}

Enemy::~Enemy()
{

}

const unsigned& Enemy::getGainExp() const
{
	return this->gainExp;
}

const bool Enemy::getDamageTimerDone() const
{
	return this->damageTimer.getElapsedTime().asMilliseconds() >= this->damageTimerMax;
}

void Enemy::resetDamageTimer()
{
	this->damageTimer.restart();
}

void Enemy::loseHP(const int hp)
{
	if (this->attributeComponent)
	{
		this->attributeComponent->loseHP(hp);
	}
}

const bool Enemy::isDead() const
{
	if (this->attributeComponent)
	{
		return this->attributeComponent->isDead();
	}

	return false;
}

const AttributeComponent* Enemy::getAttributeComp() const
{
	if (this->attributeComponent)
		return this->attributeComponent;
	else
	{
		std::cout << "ERROR::ENEMY::ATTRIBUTECOMPONENT IS NOT INITIALIZED" << "\n";
		return nullptr;
	}
}

void Enemy::update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{
}