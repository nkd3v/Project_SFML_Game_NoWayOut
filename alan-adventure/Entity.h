#ifndef ENTITY_H
#define ENTITY_H

#include "HitboxComponent.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "AttributeComponent.h"

class HitboxComponent;
class MovementComponent;
class AnimationComponent;
class AttributeComponent;

class Entity
{
private:
	void initVariables();

protected:

	sf::Sprite sprite;

	HitboxComponent* hitboxComponent;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	AttributeComponent* attributeComponent;

public:
	Entity();
	virtual ~Entity();

	void setTexture(sf::Texture& texture);
	void createHitboxComponent(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width, float height);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);
	void createAttributeComponent(int hpMax = 4, int damageMin = 1, int damageMax = 2, int moveSpeed = 1, int shootSpeed = 1);
	void createAIComponent();

	virtual MovementComponent* getMovementComponent();
	virtual AnimationComponent* getAnimationComponent();
	virtual AttributeComponent* getAttributeComponent();

	virtual const sf::Vector2f& getPosition() const;
	virtual const sf::FloatRect getGlobalBounds() const;

	virtual void setPosition(const float x, const float y);

	virtual void move(const float x, const float y, const float& dt);
	virtual void stopVelocity();
	virtual void stopVelocityX();
	virtual void stopVelocityY();

	virtual void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

#endif

