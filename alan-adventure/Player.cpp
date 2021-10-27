#include <vector>
#include "Player.h"
#include "Bullet.h"
#include <iostream>

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed)
  : anim(texture, imageCount, switchTime), speed(speed)
{
  row = 0;
  faceRight = true;
  mHealth = 5;
  faceAngle = 0.0f;
  spawnPoint = sf::Vector2f(765.0f, 408.0f);

  body.setSize(sf::Vector2f(100.0f, 100.0f));
  body.setOrigin(body.getSize() / 2.0f);
  body.setTexture(texture);
  bulletTexture.loadFromFile("assets/bullet.png");

  weaponTexture.loadFromFile("assets/bullet.png");

  weapon = Weapon(weaponTexture, bulletTexture, 0.1f);
}

Player::~Player()
{
}

void Player::Update(float deltaTime, sf::RenderTarget &window)
{
  sf::Vector2f movement(0.0f, 0.0f);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    movement.x -= speed * deltaTime;
    faceAngle = 180;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    movement.x += speed * deltaTime;
    faceAngle = 0;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    movement.y -= speed * deltaTime;
    faceAngle = 90;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
    movement.y += speed * deltaTime;
    faceAngle = 270;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    weapon.Shoot(body.getPosition(), faceAngle);
  }

  if (movement.x == 0)
  {
    row = 0;
  }
  else if (movement.x != 0)
  {
    row = 1;

    if (movement.x > 0.0f)
      faceRight = true;
    else
      faceRight = false;
  }

  if (mHealth <= 0)
  {
    died = true;
    body.setPosition(sf::Vector2f(765.0f, 408.0f));
    mHealth = 5;
  }

  anim.Update(row, deltaTime, faceRight);
  body.setTextureRect(anim.uvRect);
  body.move(movement);

  weapon.Update(deltaTime);
}

void Player::Draw(sf::RenderWindow &window)
{
  window.draw(body);
  weapon.Draw(window);
  playerUI.SetHeart(mHealth, window);
}

void Player::TakeDamage(int dmg)
{
  mHealth -= dmg;
}
