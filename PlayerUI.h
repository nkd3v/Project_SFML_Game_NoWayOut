#pragma once
#include <SFML/Graphics.hpp>

class PlayerUI
{
private:
  sf::Sprite mHeart;
  sf::Vector2f heartSize;

public:
  PlayerUI(sf::Sprite sHeart);
  ~PlayerUI();

  void SetHeart(int health, sf::RenderWindow &window) const;
};