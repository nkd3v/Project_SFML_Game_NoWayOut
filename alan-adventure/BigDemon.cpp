#include "stdafx.h"
#include "BigDemon.h"

BigDemon::BigDemon(float x, float y, sf::Texture& texture_sheet, Entity& player)
{
	this->initVariables();

	this->createHitboxComponent(this->sprite, 8.f, 0.f, 48.f, 64.f);
	this->createMovementComponent(70.f, 800.f, 500.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(6, 4, 4);

	this->setPosition(x, y);
	this->initAnimations();

	this->follow = new AI(*this, player);
}


BigDemon::~BigDemon()
{
	delete this->follow;
}

void BigDemon::initVariables()
{
	gainScore = 200;
}

void BigDemon::initAnimations()
{
	this->animationComponent->addAnimation("IDLE", 25.f, 0, 0, 3, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_DOWN", 11.f, 0, 1, 3, 1, 64, 64);
	this->animationComponent->addAnimation("WALK_LEFT", 11.f, 0, 1, 3, 1, 64, 64);
	this->animationComponent->addAnimation("WALK_RIGHT", 11.f, 0, 2, 3, 2, 64, 64);
	this->animationComponent->addAnimation("WALK_UP", 11.f, 0, 2, 3, 2, 64, 64);
}

void BigDemon::updateAnimation(const float& dt)
{
	if (this->movementComponent->getState(IDLE))
	{
		this->animationComponent->play("IDLE", dt);
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->animationComponent->play("WALK_LEFT", dt);
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		this->animationComponent->play("WALK_RIGHT", dt);
	}
	else if (this->movementComponent->getState(MOVING_UP))
	{
		this->animationComponent->play("WALK_UP", dt);
	}
	else if (this->movementComponent->getState(MOVING_DOWN))
	{
		this->animationComponent->play("WALK_DOWN", dt);
	}
}

void BigDemon::update(const float& dt)
{
	Enemy::update(dt);

	this->movementComponent->update(dt);

	this->updateAnimation(dt);

	this->hitboxComponent->update();

	this->follow->update(dt);
}

void BigDemon::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
