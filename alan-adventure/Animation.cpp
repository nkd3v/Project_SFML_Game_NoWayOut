#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
  : m_imageCount{imageCount}, m_switchTime{switchTime}
{
  m_totalTime = 0.0f;
  m_currentImage.x = 0;

  uvRect.width = texture->getSize().x / m_imageCount.x;
  uvRect.height = texture->getSize().y / m_imageCount.y;
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime, bool faceRight)
{
  m_currentImage.y = row;
  m_totalTime += deltaTime;

  if (m_totalTime >= m_switchTime)
  {
    m_totalTime -= m_switchTime;
    m_currentImage.x = (m_currentImage.x + 1) % m_imageCount.x;
  }

  uvRect.top = m_currentImage.y * uvRect.height;

  if (faceRight)
  {
    uvRect.left = m_currentImage.x * abs(uvRect.width);
    uvRect.width = abs(uvRect.width);
  }
  else
  {
    uvRect.left = (m_currentImage.x + 1) * abs(uvRect.width);
    uvRect.width = -abs(uvRect.width);
  }
}