#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{

}

void Player::initComponents()
{

}

void Player::initAnimations()
{
	this->animationComponent->addAnimation("IDLE",       15.f, 0, 0, 3, 0, 32, 64);
	this->animationComponent->addAnimation("WALK_DOWN",  11.f, 0, 1, 3, 1, 32, 64);
	this->animationComponent->addAnimation("WALK_LEFT",  11.f, 0, 1, 3, 1, 32, 64);
	this->animationComponent->addAnimation("WALK_RIGHT", 11.f, 0, 2, 3, 2, 32, 64);
	this->animationComponent->addAnimation("WALK_UP",    11.f, 0, 2, 3, 2, 32, 64);
}

Player::Player(float x, float y, sf::Texture& textureSheet)
{
	initVariables();

	createHitboxComponent(sprite, 0.f, 0.f, 0.f, 0.f);
	createMovementComponent(140.f, 1400.f, 1000.f);
	createAnimationComponent(textureSheet);

	setPosition(x, y);
	initAnimations();
}

Player::~Player()
{
}

void Player::loseHP(const int hp)
{
}

void Player::gainHP(const int hp)
{
}

void Player::updateAnimation(const float& dt)
{
	if (this->movementComponent->getState(IDLE))
	{
		this->animationComponent->play("IDLE", dt);
		std::cout << "IDLE\n";
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->animationComponent->play("WALK_LEFT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
		std::cout << "WALK_LEFT\n";
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
		std::cout << "WALK_RIGHT\n";
	}
	else if (this->movementComponent->getState(MOVING_UP))
	{
		this->animationComponent->play("WALK_UP", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
		std::cout << "WALK_UP\n";
	}
	else if (this->movementComponent->getState(MOVING_DOWN))
	{
		this->animationComponent->play("WALK_DOWN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
		std::cout << "WALK_DOWN\n";
	}
}

void Player::update(const float& dt, sf::Vector2f& mousePosView, const sf::View& view)
{
	movementComponent->update(dt);

	updateAnimation(dt);

	hitboxComponent->update();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
