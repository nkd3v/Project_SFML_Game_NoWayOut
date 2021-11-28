#include "stdafx.h"
#include "Necromancer.h"

Necromancer::Necromancer(float x, float y, sf::Texture& texture_sheet, Entity& player) :
	player(player)
{
	initVariables();

	this->createHitboxComponent(this->sprite, 4.f, 32.f, 24.f, 32.f);
	this->createMovementComponent(140.f, 800.f, 500.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(16, 1, 2);

	this->setPosition(x, y);
	this->initAnimations();
	playerHitSound.setBuffer(am.getSoundBuffer("PLAYER_HIT"));

	buffManager = std::make_unique<BuffManager>(*this);

	follow = new AIEvade(*this, player);
}

Necromancer::~Necromancer()
{
	delete follow;
	delete bow;
}

void Necromancer::initVariables()
{
	gainScore = 1000;
	bow = new Bow(*this, "", "FIREBALL");
	bow->setCooldown(2.f);
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

	bool warped = false;
	if (follow->canWarp())
	{
		warped = true;
		buffManager->createBuff(WARP, 3.f);
	}

	this->follow->update(dt);

	if (warped)
	{
		buffManager->createBuff(WARP, 3.f);
	}

	Player& p = dynamic_cast<Player&>(player);
	for (const auto& bullet : bow->getBullets())
	{
		if (bullet->getGlobalBounds().intersects(p.getGlobalBounds()))
		{
			float angle = vectorAngle(bullet->getCenter(), p.getCenter());
			p.move(100.f * cos(angle), 100.f * sin(angle), dt);

			int dmgMin = getAttributeComponent()->damageMin;
			int dmgMax = getAttributeComponent()->damageMax;


			int dmg = dmgMin + rand() % (dmgMax - dmgMin + 1) - 1;
			p.loseHP(dmg);
			bullet->kill();
			continue;
		}
	}
	
	bow->shoot(getCenter(), vectorAngle(getPosition(), player.getPosition()));
	bow->update(dt);

	buffManager->update();
}

void Necromancer::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	hitboxComponent->render(target);
	bow->render(target);
	buffManager->render(target);
}
