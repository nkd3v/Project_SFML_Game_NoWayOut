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
  spawnPoint = sf::Vector2f(765.0f, 408.0f);

  body.setSize(sf::Vector2f(100.0f, 100.0f));
  body.setOrigin(body.getSize() / 2.0f);
  body.setTexture(texture);
  bulletTexture.loadFromFile("assets/bullet.png");
}

Player::~Player()
{
}

void Player::Update(float deltaTime, sf::RenderTarget &window)
{
  sf::Vector2f movement(0.0f, 0.0f);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    movement.x -= speed * deltaTime;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    movement.x += speed * deltaTime;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    movement.y -= speed * deltaTime;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    movement.y += speed * deltaTime;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    sf::Vector2f delta = window.mapPixelToCoords(sf::Mouse::getPosition()) - body.getPosition();
    float angle = atan2(delta.y, delta.x);
    bullets.emplace_back(Bullet(bulletTexture, body.getPosition(), 1000.0f, angle));
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

  if (mHealth == 0)
  {
    body.setPosition(sf::Vector2f(765.0f, 408.0f));
    mHealth = 5;
  }

  anim.Update(row, deltaTime, faceRight);
  body.setTextureRect(anim.uvRect);
  body.move(movement);

  for (auto& bullet : bullets)
  {
    bullet.Update(deltaTime);
  }
}

void Player::Draw(sf::RenderWindow &window)
{

  window.draw(body);
  for (auto& bullet : bullets)
  {
    bullet.Draw(window);
  }
  playerUI.SetHeart(mHealth, window);
}