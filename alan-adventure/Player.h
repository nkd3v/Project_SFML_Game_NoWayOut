#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"
#include "Collider.h"
#include "PlayerUI.h"
#include "Bullet.h"
#include "Weapon.h"

class Player
{
public:
  Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
  ~Player();

  void Update(float deltaTime, sf::RenderTarget &window);
  void Draw(sf::RenderWindow &window);

  void SetPosition(const sf::Vector2f &pos) { body.setPosition(pos); }
  sf::Vector2f GetPosition() { return body.getPosition(); }
  Collider GetCollider() { return Collider(body); }
  void TakeDamage(int dmg) { mHealth -= dmg; }

  PlayerUI playerUI;
  sf::RectangleShape body;

  Weapon weapon{};
private:
  int mHealth;
  Animation anim;
  unsigned int row;
  float speed;
  bool faceRight;
  sf::Vector2f spawnPoint;
  float faceAngle;
  sf::Texture bulletTexture;
  sf::Texture weaponTexture;
};
