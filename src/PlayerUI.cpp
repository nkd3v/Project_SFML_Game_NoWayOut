#include "PlayerUI.h"

PlayerUI::PlayerUI()
{
  mHeartTexture.loadFromFile("./assets/UI/Heart.png");

  mHeart.setTexture(mHeartTexture);
  mHeart.setScale(sf::Vector2f(2.0f, 2.0f));

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
    iHeart.setPosition(firstHeartPos + sf::Vector2f(i * heartSize.x, 0.0f));
    window.draw(iHeart);
  }
}