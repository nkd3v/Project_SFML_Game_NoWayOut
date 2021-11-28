#include "stdafx.h"
#include "PlayerGUI.h"

PlayerGUI::PlayerGUI(Player *player, BuffManager *buffManager)
  : player(player), buffManager(buffManager)
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
  heartSprite.setTexture(am.getTexture("HEART"));
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
  if (score >= 0 && score < 800)
    mapLevelText.setString("Level: 1/4");
  else if (score >= 800 && score < 4000)
    mapLevelText.setString("Level: 2/4");
  else if (score >= 4000 && score < 9000)
    mapLevelText.setString("Level: 3/4");
  else if (score >= 9000)
    mapLevelText.setString("Level: 4/4");
}

void PlayerGUI::updateScorePanel()
{
  scoreText.setString("Score: " + std::to_string(player->getAttributeComponent()->score));
}

void PlayerGUI::updateBuffPanel()
{
}

void PlayerGUI::update()
{
  updateHPBar();
  updateMapLevel();
  updateScorePanel();
  updateBuffPanel();
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
  mapLevelPos = target->mapPixelToCoords(sf::Vector2i(640, 10));
  mapLevelText.setPosition(mapLevelPos);

  target->draw(mapLevelText);
}

void PlayerGUI::renderScorePanel(sf::RenderTarget* target)
{
  scorePos = target->mapPixelToCoords(sf::Vector2i(370, 10));
  scoreText.setPosition(scorePos);

  target->draw(scoreText);
}

void PlayerGUI::renderBuffPanel(sf::RenderTarget* target)
{
  buffPos = target->mapPixelToCoords(sf::Vector2i(20, 755));
  for (int i = 0, j = 0; i < buffManager->getBuffs().size(); i++)
  {
    const auto& buff = buffManager->getBuffs()[i];
    if (buff->getName() == "Swift buff")
    {
      buffSprite.setTexture(am.getTexture("SWIFTNESS_BUFF"));
      buffSprite.setPosition(buffPos + sf::Vector2f(36.f * j++, 0.f));
      target->draw(buffSprite);
    }
    else if (buff->getName() == "Rapid Fire Buff")
    {
      buffSprite.setTexture(am.getTexture("RAPID_FIRE_BUFF"));
      buffSprite.setPosition(buffPos + sf::Vector2f(36.f * j++, 0.f));
      target->draw(buffSprite);
    }
  }
}

void PlayerGUI::render(sf::RenderTarget* target)
{
  renderHPBar(target);
  renderMapLevel(target);
  renderScorePanel(target);
  renderBuffPanel(target);
}
