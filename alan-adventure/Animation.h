#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
  enum FaceDir { LEFT, RIGHT, UP, DOWN };

  Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
  ~Animation();

  void Update(int row, float deltaTime, bool faceRight);
  void Update(int row, float deltaTime, FaceDir faceDir);

private:

public:
  sf::IntRect uvRect;

private:
  sf::Vector2u m_imageCount;
  sf::Vector2u m_currentImage;

  float m_totalTime;
  float m_switchTime;
};