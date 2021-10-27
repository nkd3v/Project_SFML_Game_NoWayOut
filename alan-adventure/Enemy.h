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
  sf::Vector2f GetPosition() { return body.getPosition(); }
  Collider GetCollider() { return Collider(body); }
  sf::RectangleShape& GetBody() { return body; }

  void kill();

private:
  void updateAlive(float dt);
  void updateDie(float dt);

  sf::RectangleShape body;
  Animation anim;
  unsigned int row{};
  float mSpeed;
  sf::Transformable* mTargetRef{};
  bool faceRight{};
  int hp;

  sf::Texture bodyTexture;
  Animation dieAnim;
  sf::Texture dieTexture;
  bool isAlive = true;
};