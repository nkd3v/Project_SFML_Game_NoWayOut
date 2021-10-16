#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Animation.h"

class Enemy
{
public:
  Enemy(
    sf::Texture* texture,
    sf::Vector2u imageCount,
    float switchTime,
    float speed,
    sf::Vector2f size,
    sf::Vector2f position
  );
  ~Enemy();

  void Draw(sf::RenderWindow &window);
  void Update(float deltaTime);
  void SetTarget(sf::Transformable* target);
  Collider GetCollider() { return Collider(body); }
  sf::RectangleShape& GetBody() { return body; }

private:
  sf::RectangleShape body;
  Animation anim;
  unsigned int row{};
  float mSpeed;
  sf::Transformable* mTargetRef{};
  bool faceRight{};
};