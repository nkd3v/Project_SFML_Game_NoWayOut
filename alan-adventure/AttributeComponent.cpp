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

void AttributeComponent::loseHP(const int changeHP)
{
	hp -= changeHP;

	if (hp < 0)
		hp = 0;
}

void AttributeComponent::gainHP(const int changeHP)
{
	this->hp += changeHP;

	if (this->hp > this->hpMax)
		this->hp = this->hpMax;
}

const bool AttributeComponent::isDead() const
{
	return this->hp <= 0;
}

void AttributeComponent::setScore(int newScore)
{
	this->score = newScore;
}

int AttributeComponent::getScore()
{
	return score;
}

void AttributeComponent::update()
{
}



