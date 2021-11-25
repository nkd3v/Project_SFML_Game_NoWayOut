#include "stdafx.h"
#include "AttributeComponent.h"

AttributeComponent::AttributeComponent(int hpMax, int damageMin, int damageMax, int moveSpeed, int shootSpeed)
	: hp(hpMax), hpMax(hpMax), damageMin(damageMax), damageMax(damageMax), moveSpeed(moveSpeed), shootSpeed(shootSpeed)
{
	score = 0;
}

AttributeComponent::~AttributeComponent()
{
	
}

void AttributeComponent::loseHP(const int hp)
{
	this->hp -= hp;

	if (this->hp < 0)
		this->hp = 0;
}

void AttributeComponent::gainHP(const int hp)
{
	this->hp += hp;

	if (this->hp > this->hpMax)
		this->hp = this->hpMax;
}

const bool AttributeComponent::isDead() const
{
	return this->hp <= 0;
}

void AttributeComponent::setScore(int score)
{
	this->score = score;
}

int AttributeComponent::getScore()
{
	return score;
}

void AttributeComponent::update()
{
}



