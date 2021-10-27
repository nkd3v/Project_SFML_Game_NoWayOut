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
  void TakeDamage(int dmg);

  void resetHealth() { mHealth = 5; }
  void setSpeed(float t_speed) { speed = t_speed; }
  void addSpeed(float t_speed) { speed += t_speed; }
  void changeCooldown(float delta) { weapon.ChangeCooldown(delta); }

  PlayerUI playerUI;
  sf::RectangleShape body;

  bool died = false;

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
