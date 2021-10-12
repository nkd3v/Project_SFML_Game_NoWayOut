#pragma once
#include <SFML/Graphics.hpp>

class PlayerUI
{
private:
  sf::Sprite mHeart;
  sf::Vector2f heartSize;
  sf::Texture mHeartTexture;

public:
  PlayerUI();
  ~PlayerUI();

  void SetHeart(int health, sf::RenderWindow &window) const;
};