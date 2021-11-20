#include "stdafx.h"
#include "MovementComponent.h"

MovementComponent::MovementComponent(
  sf::Sprite& sprite,
  float maxVelocity,
  float acceleration,
  float deceleration
) : sprite(sprite),
  maxVelocity(maxVelocity),
  acceleration(acceleration),
  deceleration(deceleration)
{
}

MovementComponent::~MovementComponent()
{
}

const float& MovementComponent::getMaxVelocity() const
{
  return maxVelocity;
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
  return velocity;
}

const bool MovementComponent::getState(const short unsigned state) const
{
	switch (state)
	{
  case IDLE:

		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
			return true;

		break;

	case MOVING:

		if (this->velocity.x != 0.f || this->velocity.y != 0.f)
			return true;

		break;

	case MOVING_LEFT:

		if (this->velocity.x < 0.f)
			return true;

		break;

	case MOVING_RIGHT:

		if (this->velocity.x > 0.f)
			return true;

		break;

	case MOVING_UP:

		if (this->velocity.y < 0.f)
			return true;

		break;

	case MOVING_DOWN:

		if (this->velocity.y > 0.f)
			return true;

		break;
	}

	return false;
}

void MovementComponent::stopVelocity()
{
  velocity = sf::Vector2f(0.f, 0.f);
}

void MovementComponent::stopVelocityX()
{
  velocity.x = 0.f;
}

void MovementComponent::stopVelocityY()
{
  velocity.y = 0.f;
}

void MovementComponent::move(const float dirX, const float dirY, const float& dt)
{
  velocity.x += acceleration * dirX * dt;
  velocity.y += acceleration * dirY * dt;
}

void MovementComponent::update(const float& dt)
{
  if (abs(velocity.x) > abs(maxVelocity))
  {
    velocity.x = velocity.x > 0 ? maxVelocity : -maxVelocity;
  }
  if (abs(velocity.y) > abs(maxVelocity))
  {
    velocity.y = velocity.y > 0 ? maxVelocity : -maxVelocity;
  }
  if (velocity.x != 0)
  {
    float newVelocityX = abs(velocity.x) - deceleration * dt;
    if (newVelocityX < 0) newVelocityX = 0;
    velocity.x = velocity.x > 0 ? newVelocityX : -newVelocityX;
  }
  if (velocity.y != 0)
  {
    float newVelocityY = abs(velocity.y) - deceleration * dt;
    if (newVelocityY < 0) newVelocityY = 0;
    velocity.y = velocity.y > 0 ? newVelocityY : -newVelocityY;
  }

	sprite.move(velocity * dt);
}
