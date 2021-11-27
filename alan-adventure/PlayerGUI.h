#pragma once

#include "Player.h"

class PlayerGUI
{
private:
  Player *player;

  sf::Sprite heartSprite;

  sf::IntRect fullHeartRect;
  sf::IntRect halfHeartRect;
  sf::IntRect emptyHeartRect;

  sf::Vector2f heartSize;
  sf::Texture heartTexture;

  sf::Text scoreText;
  sf::Text mapLevelText;

  sf::Vector2f HPBarPos;
  sf::Vector2f scorePos;
  sf::Vector2f mapLevelPos;

  void initHPBar();
  void initMapLevel();
  void initScorePanel();

  void updateHPBar();
  void updateMapLevel();
  void updateScorePanel();

  void renderHPBar(sf::RenderTarget* target);
  void renderMapLevel(sf::RenderTarget* target);
  void renderScorePanel(sf::RenderTarget* target);

public:
  PlayerGUI(Player *player);
  ~PlayerGUI();

  void update();
  void render(sf::RenderTarget* target);
};