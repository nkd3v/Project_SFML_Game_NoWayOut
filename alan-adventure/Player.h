#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player :
  public Entity
{
private:
  void initVariables();
  void initComponents();
  void initAnimations();

public:
  Player(float x, float y, sf::Texture& textureSheet);
  virtual ~Player();

  void loseHP(const int hp);
  void gainHP(const int hp);

  void updateAnimation(const float& dt);
  void update(const float& dt, sf::Vector2f& mousePosView, const sf::View& view);

  void render(sf::RenderTarget& target);
};

#endif // !PLAYER_H
