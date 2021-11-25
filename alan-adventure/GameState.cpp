#include "stdafx.h"
#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states)
  : State(window, states)
{
  initTextures();
  initMap();
  initPlayers();
  initPlayerGUI();
  initEnemySystem();
  initItemManager();
  initEnemySpawner();
  initView();
}

GameState::~GameState()
{
  delete player;
  delete enemySpawner;
  delete enemySystem;
  delete itemManager;

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

  if (!textures["HEALTH_POTION"].loadFromFile("assets/Items/potions.png"))
  {
    throw "Error: Loading health potion texture failed!";
  }
  if (!textures["RAPID_FIRE_POTION"].loadFromFile("assets/Items/potions.png"))
  {
    throw "Error: Loading fast shooting potion texture failed!";
  }
  if (!textures["SWIFT_POTION"].loadFromFile("assets/Items/potions.png"))
  {
    throw "Error: Loading speed potion texture failed!";
  }
  if (!textures["INVISIBLE_POTION"].loadFromFile("assets/Items/potions.png"))
  {
    throw "Error: Loading INVISIBLE potion texture failed!";
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
  enemySystem = new EnemySystem(activeEnemies, textures, *player);
}

void GameState::initEnemySpawner()
{
  enemySpawner = new EnemySpawner(*enemySystem);

  enemySpawner->addSpawner(sf::Vector2f(110, 159), 2, 10);
  enemySpawner->addSpawner(sf::Vector2f(561, 125), 2, 10);
  enemySpawner->addSpawner(sf::Vector2f(174, 448), 2, 10);
}

void GameState::initItemManager()
{
  itemManager = new ItemManager(items, textures, *player);
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
  view.zoom(.9f);
}

void GameState::updateInput(const float& dt)
{

}

void GameState::updatePlayer(const float& dt)
{
  player->update(dt, mousePosView, view);
}

void GameState::updateItemsInteraction(const float& dt)
{
  itemManager->update(dt);
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
      player->getAttributeComponent()->score++;
      enemySystem->removeEnemy(index);
      continue;
    }

    ++index;
  }

  if (player->getAttributeComponent()->isDead())
  {
    newState = std::make_unique<ScoreboardState>(window, states, player->getAttributeComponent()->score);
    quit = true;
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
      itemManager->createItem(rand() % 4, enemy->getPosition().x, enemy->getPosition().y);
      continue;
    }
  }

  if (enemy->getGlobalBounds().intersects(player->getGlobalBounds()) && player->getDamageTimer())
  {
    int dmg = enemy->getAttributeComp()->damageMax;
    player->loseHP(dmg);
  }
}

void GameState::updateEnemySpawner(const float& dt)
{
  enemySpawner->update(dt);
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

void GameState::update(const float& dt, sf::RenderTarget* target)
{
  updateSFMLEvents(target);
  updateMousePositions(&view);
  updateKeytime(dt);
  updateInput(dt);

  if (!paused)
  {
    updatePlayer(dt);
    updatePlayerInput(dt);
    updateCombatAndEnemies(dt);
    updateEnemySpawner(dt);
    updateItemsInteraction(dt);
    playerGUI->update();
  }
}

void GameState::render(sf::RenderTarget* target)
{
  if (!target)
    target = window;

  target->setView(view);

  target->draw(map);

  itemManager->render(target);

  playerGUI->render(target);

  for (auto* enemy : activeEnemies)
  {
    enemy->render(*target);
  }

  player->render(*target);
}
