#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	this->initVariables();
	this->initAnimations();
}

Enemy::~Enemy()
{

}

void Enemy::initVariables()
{
	this->gainScore = 10;
	this->damageTimerMax = 1000;
}

void Enemy::initAnimations()
{

}

const unsigned& Enemy::getGainScore() const
{
	return this->gainScore;
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
		return nullptr;
}

void Enemy::update(const float& dt)
{
}