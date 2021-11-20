#pragma once

#include "SFML/Graphics.hpp"

#include "HitboxComponent.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"

class Entity
{
private:
  void initVariables();

protected:
  sf::Sprite sprite;

  HitboxComponent* hitboxComponent;
  MovementComponent* movementComponent;
  AnimationComponent* animationComponent;

public:
  Entity();
  virtual ~Entity();

  void setTexture(sf::Texture& texture);
  void createHitboxComponent(sf::Sprite sprite,
    float offsetX, float offsetY,
    float width, float height);
  void createMovementComponent(float maxVelocity, float acceleration, float deceleration);
  void createAnimationComponent(sf::Texture& textureSheet);

  virtual void setPosition(const float x, const float y);

  virtual void move(const float x, const float y, const float& dt);

  virtual void update(const float& dt, sf::Vector2f& mousePosView, const sf::View& view) = 0;
  virtual void render(sf::RenderTarget& target) = 0;
};

