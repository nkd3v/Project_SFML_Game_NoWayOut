#pragma once

#include <vector>
#include <string>
#include <map>

#include "State.h"
#include "ScoreBoard.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemySystem.h"
#include "TileMap.h"
#include "PlayerGUI.h"

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

  std::vector<Enemy*> activeEnemies;
  EnemySystem* enemySystem;

  TileMap* tileMap;

  PlayerGUI* playerGUI;

  std::map<std::string, sf::Texture> textures;

  sf::Sprite map;
  sf::Texture mapTexture;

  void initTextures();
  void initView();

  void initPlayers();
  void initPlayerGUI();
  void initEnemySystem();
  void initTileMap();
  void initMap();

public:
  GameState(sf::RenderWindow* window);
  virtual ~GameState();

  void updateInput(const float& dt);
  void updatePlayerInput(const float& dt);
  void updatePlayer(const float& dt);
  void updateCombatAndEnemies(const float& dt);
  void updateCombat(Enemy* enemy, const int index, const float& dt);
  void update(const float& dt);

  void render(sf::RenderTarget* target = nullptr);
};

