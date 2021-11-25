#include "stdafx.h"
#include "Skelet.h"

void Skelet::initVariables()
{
}

void Skelet::initAnimations()
{
	this->animationComponent->addAnimation("IDLE",       25.f, 0, 0, 3, 0, 32, 32);
	this->animationComponent->addAnimation("WALK_DOWN",  11.f, 0, 1, 3, 1, 32, 32);
	this->animationComponent->addAnimation("WALK_LEFT",  11.f, 0, 1, 3, 1, 32, 32);
	this->animationComponent->addAnimation("WALK_RIGHT", 11.f, 0, 2, 3, 2, 32, 32);
	this->animationComponent->addAnimation("WALK_UP",    11.f, 0, 2, 3, 2, 32, 32);
}

//Constructors / Destructors
Skelet::Skelet(float x, float y, sf::Texture& texture_sheet, Entity& player)
{
	initVariables();

	this->createHitboxComponent(this->sprite, 8.f, 10.f, 16.f, 18.f);
	this->createMovementComponent(70.f, 800.f, 500.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(1);

	this->setPosition(x, y);
	this->initAnimations();

	this->follow = new AIFollow(*this, player);
}


Skelet::~Skelet()
{
	delete this->follow;
}

void Skelet::updateAnimation(const float& dt)
{
	if (this->movementComponent->getState(IDLE))
	{
		this->animationComponent->play("IDLE", dt);
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->animationComponent->play("WALK_LEFT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_UP))
	{
		this->animationComponent->play("WALK_UP", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_DOWN))
	{
		this->animationComponent->play("WALK_DOWN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
}

void Skelet::update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{
	Enemy::update(dt, mouse_pos_view, view);

	this->movementComponent->update(dt);

	this->updateAnimation(dt);

	this->hitboxComponent->update();

	this->follow->update(dt);
}

void Skelet::render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox)
{
	target.draw(this->sprite);

	if (show_hitbox)
		this->hitboxComponent->render(target);
}
