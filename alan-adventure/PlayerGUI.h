#pragma once

#include "Player.h"
#include "BuffManager.h"

class PlayerGUI
{
private:
  Player *player;

  sf::Sprite heartSprite;

  sf::IntRect fullHeartRect;
  sf::IntRect halfHeartRect;
  sf::IntRect emptyHeartRect;

  sf::Vector2f heartSize;

  sf::Sprite buffSprite;

  sf::Text scoreText;
  sf::Text mapLevelText;

  sf::Vector2f HPBarPos;
  sf::Vector2f scorePos;
  sf::Vector2f mapLevelPos;
  sf::Vector2f buffPos;

  BuffManager* buffManager;

  void initHPBar();
  void initMapLevel();
  void initScorePanel();

  void updateHPBar();
  void updateMapLevel();
  void updateScorePanel();
  void updateBuffPanel();

  void renderHPBar(sf::RenderTarget* target);
  void renderMapLevel(sf::RenderTarget* target);
  void renderScorePanel(sf::RenderTarget* target);
  void renderBuffPanel(sf::RenderTarget* target);

public:
  PlayerGUI(Player *player, BuffManager* buffManager);
  ~PlayerGUI();

  void update();
  void render(sf::RenderTarget* target);
};