#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "PlayerUI.h"

class Player
{
public:
  enum FaceDir { LEFT, RIGHT, UP, DOWN };

  Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
  ~Player();

  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);

  void SetPosition(const sf::Vector2f &pos) { body.setPosition(pos); }
  sf::Vector2f GetPosition() { return body.getPosition(); }
  Collider GetCollider() { return Collider(body); }
  void TakeDamage(int dmg) { mHealth -= dmg; }

  PlayerUI playerUI;

private:
  int mHealth;
  sf::RectangleShape body;
  Animation anim;
  unsigned int row;
  float speed;
  bool faceRight;
  sf::Vector2f spawnPoint;
};
