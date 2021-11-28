#include "stdafx.h"
#include "Necromancer.h"

Necromancer::Necromancer(float x, float y, sf::Texture& texture_sheet, Entity& player)
{
	initVariables();

	this->createHitboxComponent(this->sprite, 4.f, 32.f, 24.f, 32.f);
	this->createMovementComponent(70.f, 800.f, 500.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(2, 1, 1);

	this->setPosition(x, y);
	this->initAnimations();

	follow = new AIEvade(*this, player);
}

Necromancer::~Necromancer()
{
	delete follow;
}

void Necromancer::initVariables()
{
	gainScore = 1000;
}

void Necromancer::initAnimations()
{
	this->animationComponent->addAnimation("IDLE",       25.f, 0, 0, 3, 0, 32, 64);
	this->animationComponent->addAnimation("WALK_DOWN",  11.f, 0, 1, 3, 1, 32, 64);
	this->animationComponent->addAnimation("WALK_LEFT",  11.f, 0, 1, 3, 1, 32, 64);
	this->animationComponent->addAnimation("WALK_RIGHT", 11.f, 0, 2, 3, 2, 32, 64);
	this->animationComponent->addAnimation("WALK_UP",    11.f, 0, 2, 3, 2, 32, 64);
}

void Necromancer::updateAnimation(const float& dt)
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

void Necromancer::update(const float& dt)
{
	Enemy::update(dt);

	this->movementComponent->update(dt);

	this->updateAnimation(dt);

	this->hitboxComponent->update();

	this->follow->update(dt);
}

void Necromancer::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	hitboxComponent->render(target);
}
