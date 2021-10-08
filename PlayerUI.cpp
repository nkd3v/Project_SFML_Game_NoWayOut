#include "PlayerUI.h"

PlayerUI::PlayerUI(sf::Sprite heart)
  : mHeart(heart)
{
  heartSize.x = mHeart.getTexture()->getSize().x * mHeart.getScale().x;
  heartSize.y = mHeart.getTexture()->getSize().y * mHeart.getScale().y;

  mHeart.setOrigin(heartSize / 2.0f);
}

PlayerUI::~PlayerUI()
{

}

void PlayerUI::SetHeart(int health, sf::RenderWindow &window) const
{
  sf::Vector2f firstHeartPos = window.mapPixelToCoords(sf::Vector2i(60, 60));

  for (int i = 0; i < health; i++)
  {
    sf::Sprite iHeart(mHeart);
    iHeart.setPosition(firstHeartPos.x + i * heartSize.x, firstHeartPos.y);
    window.draw(iHeart);
  }
}