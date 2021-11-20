#pragma once

#include <vector>
#include <string>
#include <map>

#include "State.h"
#include "ScoreBoard.h"
#include "Player.h"
#include "Enemy.h"

class GameState :
    public State
{
private:
  sf::View view;
  sf::Vector2i viewGridPosition;
  sf::RenderTexture renderTexture;
  sf::Sprite renderSprite;

  sf::Font font;
  
  sf::Clock keyTimer;
  float keyTimeMax;

  sf::Text debugText;

  Player *player;
  sf::Texture texture;

  std::map<std::string, sf::Texture> textures;

  void initTextures();
  void initPlayers();
  void initView();

public:
  GameState(sf::RenderWindow* window);
  virtual ~GameState();

  void updateInput(const float& dt);
  void updatePlayer(const float& dt);
  void updatePlayerInput(const float& dt);
  void update(const float& dt);

  void render(sf::RenderTarget* target = nullptr);
};

