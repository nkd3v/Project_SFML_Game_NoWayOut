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

  sf::Font font;

  sf::Vector2f HPBarPos;
  sf::Vector2f scorePos;

  void initHPBar();
  void initScore();

  void updateHPBar();
  void updateScorePanel();

  void renderHPBar(sf::RenderTarget* target);
  void renderScorePanel(sf::RenderTarget* target);

public:
  PlayerGUI(Player *player);
  ~PlayerGUI();

  void update();
  void render(sf::RenderTarget* target);
};