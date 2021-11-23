#pragma once

#include "States.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemySystem.h"
#include "EnemySpawner.h"
#include "TileMap.h"
#include "PlayerGUI.h"
#include "HealthPotion.h"

class GameState :
    public State
{
private:
  sf::View view;
  sf::Vector2i viewGridPosition;
  sf::RenderTexture renderTexture;
  sf::Sprite renderSprite;

  HealthPotion* healthPotion;

  sf::Font font;
  
  sf::Clock keyTimer;
  float keyTimeMax;

  sf::Text debugText;

  Player *player;
  sf::Texture texture;

  std::vector<Enemy*> activeEnemies;
  EnemySystem* enemySystem;
  EnemySpawner* enemySpawner;

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
  void initEnemySpawner();
  void initTileMap();
  void initMap();

public:
  GameState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states);
  virtual ~GameState();

  void updateInput(const float& dt);
  void updatePlayerInput(const float& dt);
  void updatePlayer(const float& dt);
  void updateCombatAndEnemies(const float& dt);
  void updateCombat(Enemy* enemy, const int index, const float& dt);
  void updateEnemySpawner(const float& dt);
  void update(const float& dt, sf::RenderTarget* target);

  void render(sf::RenderTarget* target = nullptr);
};

