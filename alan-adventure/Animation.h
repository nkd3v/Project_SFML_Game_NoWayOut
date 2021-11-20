#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
  enum FaceDir { LEFT, RIGHT, UP, DOWN };

  Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
  Animation() = default;
  ~Animation();

  void update(int row, float deltaTime, bool faceRight);

private:

public:
  sf::IntRect uvRect;
  bool ended = false;

private:
  sf::Vector2u m_imageCount;
  sf::Vector2u m_currentImage;

  float m_totalTime{};
  float m_switchTime = 0.25f;
};