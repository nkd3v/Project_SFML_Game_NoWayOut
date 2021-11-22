#include "stdafx.h"
#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
  : State(window)
{
  initTextures();
  initMap();
  initPlayers();
  initPlayerGUI();
  initEnemySystem();
  initView();
}

GameState::~GameState()
{
  delete player;

  for (size_t i = 0; i < this->activeEnemies.size(); i++)
  {
    delete this->activeEnemies[i];
  }
}

void GameState::initTextures()
{
  if (!textures["PLAYER_SHEET"].loadFromFile("assets/Heroes/elf_m.png"))
  {
    throw "Error: Loading Player texture failed!";
  }
  if (!textures["SKELET"].loadFromFile("assets/Enemy/skelet.png"))
  {
    throw "Error: Loading Skelet texture failed!";
  }
  if (!textures["BIG_DEMON"].loadFromFile("assets/Enemy/big_demon.png"))
  {
    throw "Error: Loading Big Demon texture failed!";
  }
  if (!textures["ORC_WARRIOR"].loadFromFile("assets/Enemy/orc_warrior.png"))
  {
    throw "Error: Loading Orc Warrior texture failed!";
  }
}

void GameState::initPlayers()
{
  player = new Player(50, 50, textures["PLAYER_SHEET"]);
}

void GameState::initPlayerGUI()
{
  playerGUI = new PlayerGUI(player);
}

void GameState::initEnemySystem()
{
  enemySystem = new EnemySystem(this->activeEnemies, this->textures, *this->player);
  enemySystem->createEnemy(SKELET, 100, 100);
  enemySystem->createEnemy(BIG_DEMON, 100, 100);
  enemySystem->createEnemy(ORC_WARRIOR, 200, 100);
}

void GameState::initTileMap()
{

}

void GameState::initMap()
{
  mapTexture.loadFromFile("assets/Maps/stage.png");
  map.setTexture(mapTexture);
}

void GameState::initView()
{
  view.setSize(800.f, 800.f);
  view.setCenter(320.f, 311.f);
  view.zoom(.8f);
}

void GameState::updateInput(const float& dt)
{

}

void GameState::updatePlayer(const float& dt)
{
  player->update(dt, mousePosView, view);
}

void GameState::updateCombatAndEnemies(const float& dt)
{
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    player->attack(mousePosView);
  }

  unsigned index = 0;
  for (auto* enemy : activeEnemies)
  {
    enemy->update(dt, mousePosView, view);

    updateCombat(enemy, index, dt);

    if (enemy->isDead())
    {
      player->gainEXP(enemy->getGainExp());
      enemySystem->removeEnemy(index);
      continue;
    }
    //else if (enemy->getDamageTimerDone())
    //{
    //  this->enemySystem->removeEnemy(index);
    //  continue;
    //}

    ++index;
  }
}

void GameState::updateCombat(Enemy* enemy, const int index, const float& dt)
{
  for (const auto& bullet : player->getWeapon()->getBullets())
  {
    if (bullet->getGlobalBounds().intersects(enemy->getGlobalBounds()))
    {
      int dmg = 1;
      enemy->loseHP(dmg);
      enemy->resetDamageTimer();
      bullet->kill();
    }
  }

  if (enemy->getGlobalBounds().intersects(player->getGlobalBounds()) && player->getDamageTimer())
  {
    int dmg = enemy->getAttributeComp()->damageMax;
    player->loseHP(dmg);
  }
}

void GameState::updatePlayerInput(const float& dt)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    player->move(-1.f, 0.f, dt);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    player->move(1.f, 0.f, dt);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    player->move(0.f, -1.f, dt);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    player->move(0.f, 1.f, dt);
}

void GameState::update(const float& dt)
{
  updateMousePositions(&view);
  updateKeytime(dt);
  updateInput(dt);

  if (!paused)
  {
    updatePlayer(dt);
    updatePlayerInput(dt);
    updateCombatAndEnemies(dt);
    playerGUI->update();
  }
}

void GameState::render(sf::RenderTarget* target)
{
  if (!target)
    target = window;

  target->setView(view);

  target->draw(map);

  playerGUI->render(target);

  for (auto* enemy : activeEnemies)
  {
    enemy->render(*target);
  }

  player->render(*target);
}
