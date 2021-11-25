#include "stdafx.h"
#include "OrcWarrior.h"

//Initializer functions
void OrcWarrior::initVariables()
{

}

void OrcWarrior::initAnimations()
{
	this->animationComponent->addAnimation("IDLE", 25.f, 0, 0, 3, 0, 32, 64);
	this->animationComponent->addAnimation("WALK_DOWN", 11.f, 0, 1, 3, 1, 32, 64);
	this->animationComponent->addAnimation("WALK_LEFT", 11.f, 0, 1, 3, 1, 32, 64);
	this->animationComponent->addAnimation("WALK_RIGHT", 11.f, 0, 2, 3, 2, 32, 64);
	this->animationComponent->addAnimation("WALK_UP", 11.f, 0, 2, 3, 2, 32, 64);
	//this->animationComponent->addAnimation("ATTACK",      5.f, 0, 2, 1, 2, 60, 64);
}

void OrcWarrior::initAI()
{

}

void OrcWarrior::initGUI()
{
	this->hpBar.setFillColor(sf::Color::Red);
	this->hpBar.setSize(sf::Vector2f(60.f, 10.f));
	this->hpBar.setPosition(this->sprite.getPosition());
}

//Constructors / Destructors
OrcWarrior::OrcWarrior(float x, float y, sf::Texture& texture_sheet, Entity& player)
{
	this->initVariables();
	this->initGUI();

	this->createHitboxComponent(this->sprite, 4.f, 32.f, 24.f, 32.f);
	this->createMovementComponent(70.f, 800.f, 500.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(5);

	this->setPosition(x, y);
	this->initAnimations();

	this->follow = new AIFollow(*this, player);
}


OrcWarrior::~OrcWarrior()
{
	delete this->follow;
}

void OrcWarrior::updateAnimation(const float& dt)
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

	//if (this->damageTimer.getElapsedTime().asMilliseconds() <= this->damageTimerMax)
	//{
	//	this->sprite.setColor(sf::Color::Red);
	//}
	//else
	//	this->sprite.setColor(sf::Color::White);
}

void OrcWarrior::update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{
	Enemy::update(dt, mouse_pos_view, view);

	this->movementComponent->update(dt);

	//Update GUI REMOVE THIS!!!!
	//this->hpBar.setSize(sf::Vector2f(60.f * (static_cast<float>(this->attributeComponent->hp) / this->attributeComponent->hpMax), 10.f));
	//this->hpBar.setPosition(this->sprite.getPosition());

	//this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();

	this->follow->update(dt);
}

void OrcWarrior::render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox)
{
	target.draw(this->sprite);

	if (show_hitbox)
		this->hitboxComponent->render(target);
}
