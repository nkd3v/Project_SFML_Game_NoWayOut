#include "stdafx.h"
#include "PlayerGUI.h"

PlayerGUI::PlayerGUI(Player *player)
  : player(player)
{
  initHPBar();
  initScore();
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

void PlayerGUI::initScore()
{
  font.loadFromFile("assets/Fonts/dpcomic.ttf");
}

void PlayerGUI::updateHPBar()
{
}

void PlayerGUI::updateScorePanel()
{
}

void PlayerGUI::update()
{
  updateHPBar();
  updateScorePanel();
}

void PlayerGUI::renderHPBar(sf::RenderTarget* target)
{
  sf::Vector2f firstHeartPos = target->mapPixelToCoords(sf::Vector2i(20, 20));

  int hpMax = player->getAttributeComponent()->hpMax;
  int hp = player->getAttributeComponent()->hp;

  std::cout << hpMax << ' ' << hp << '\n';

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

void PlayerGUI::renderScorePanel(sf::RenderTarget* target)
{
  sf::Text text(std::to_string(player->getAttributeComponent()->score), font);
  text.setPosition(target->mapPixelToCoords(sf::Vector2i(60, 60)));
  target->draw(text);
}

void PlayerGUI::render(sf::RenderTarget* target)
{
  renderHPBar(target);
  renderScorePanel(target);
}
