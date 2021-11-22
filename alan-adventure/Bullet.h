#pragma once

class Bullet
{
private:
  sf::Sprite sprite;
  sf::Texture bulletTexture;

  sf::Clock timer;

  float speed;
  float angle;
  float lifespan;
  float lifetime;

  int life;

public:
  Bullet(sf::Vector2f pos, float speed, float angle);
  ~Bullet();

  void initVariables();
  void initTexture();

  void kill();

  const sf::FloatRect& getGlobalBounds() const;
  bool endofLife();

  void update(float dt);
  void render(sf::RenderTarget& target);
};

