#include "stdafx.h"
#include "PlayerGUI.h"

PlayerGUI::PlayerGUI(Player *player)
  : player(player)
{
  initHPBar();
  initMapLevel();
  initScorePanel();
}

PlayerGUI::~PlayerGUI()
{

}

void PlayerGUI::initHPBar()
{
  if (!heartTexture.loadFromFile("assets/GUI/heart.png"))
  {
    throw "Error: Could not load Heart GUI";
  }
  heartSprite.setTexture(heartTexture);
  heartSize = sf::Vector2f(32.f, 32.f);

  fullHeartRect = sf::IntRect(0, 0, 32, 32);
  halfHeartRect = sf::IntRect(32, 0, 32, 32);
  emptyHeartRect = sf::IntRect(64, 0, 32, 32);
}

void PlayerGUI::initMapLevel()
{
  mapLevelText.setFont(am.getFont("DPCOMIC"));
}

void PlayerGUI::initScorePanel()
{
  scoreText.setFont(am.getFont("DPCOMIC"));
}

void PlayerGUI::updateHPBar()
{
}

void PlayerGUI::updateMapLevel()
{
  int score = player->getAttributeComponent()->score;
  if (score >= 0 && score < 500)
    mapLevelText.setString("Level: 1");
  else if (score >= 500 && score < 2500)
    mapLevelText.setString("Level: 2");
  else if (score >= 2500)
    mapLevelText.setString("Level: 3");
}

void PlayerGUI::updateScorePanel()
{
  scoreText.setString("Score: " + std::to_string(player->getAttributeComponent()->score));
}

void PlayerGUI::update()
{
  updateHPBar();
  updateMapLevel();
  updateScorePanel();
}

void PlayerGUI::renderHPBar(sf::RenderTarget* target)
{
  sf::Vector2f firstHeartPos = target->mapPixelToCoords(sf::Vector2i(20, 20));

  int hpMax = player->getAttributeComponent()->hpMax;
  int hp = player->getAttributeComponent()->hp;

  heartSprite.setTextureRect(fullHeartRect);
  int i = 0;
  for (; i < hp / 2; i++)
  {
    heartSprite.setPosition(firstHeartPos + sf::Vector2f(i * heartSize.x, 0.f));
    target->draw(heartSprite);
  }

  heartSprite.setTextureRect(halfHeartRect);
  if (hp % 2 == 1)
  {
    heartSprite.setPosition(firstHeartPos + sf::Vector2f(i * heartSize.x, 0.f));
    target->draw(heartSprite);
    i++;
  }

  heartSprite.setTextureRect(emptyHeartRect);
  for (int j = 0; j < (hpMax - hp) / 2; j++, i++)
  {
    heartSprite.setPosition(firstHeartPos + sf::Vector2f(i * heartSize.x, 0.f));
    target->draw(heartSprite);
  }
}

void PlayerGUI::renderMapLevel(sf::RenderTarget* target)
{
  sf::Vector2f mapLevelPos = target->mapPixelToCoords(sf::Vector2i(680, 10));
  mapLevelText.setPosition(mapLevelPos);

  target->draw(mapLevelText);
}

void PlayerGUI::renderScorePanel(sf::RenderTarget* target)
{
  sf::Vector2f scorePos = target->mapPixelToCoords(sf::Vector2i(370, 10));
  scoreText.setPosition(scorePos);

  target->draw(scoreText);
}

void PlayerGUI::render(sf::RenderTarget* target)
{
  renderHPBar(target);
  renderMapLevel(target);
  renderScorePanel(target);
}
