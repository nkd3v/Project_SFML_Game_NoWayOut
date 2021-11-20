#include "stdafx.h"
#include "Entity.h"

void Entity::initVariables()
{
	hitboxComponent = NULL;
	movementComponent = NULL;
	animationComponent = NULL;
}

Entity::Entity()
{
	initVariables();
}

Entity::~Entity()
{
	delete hitboxComponent;
	delete movementComponent;
	delete animationComponent;
}

void Entity::setTexture(sf::Texture& texture)
{
	sprite.setTexture(texture);
}

void Entity::createHitboxComponent(sf::Sprite sprite, float offsetX, float offsetY, float width, float height)
{
	hitboxComponent = new HitboxComponent(sprite, offsetX, offsetY, width, height);
}

void Entity::createMovementComponent(float maxVelocity, float acceleration, float deceleration)
{
	movementComponent = new MovementComponent(sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& textureSheet)
{
	animationComponent = new AnimationComponent(sprite, textureSheet);
}

void Entity::setPosition(const float x, const float y)
{
	if (hitboxComponent)
		hitboxComponent->setPosition(x, y);
	else
		sprite.setPosition(x, y);
}

void Entity::move(const float dirX, const float dirY, const float& dt)
{
	if (movementComponent)
		movementComponent->move(dirX, dirY, dt);
}
