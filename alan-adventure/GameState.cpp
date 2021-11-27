#include "stdafx.h"
#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states)
  : State(window, states)
{
  initSound();
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

void GameState::initSound()
{
  bgMusic.setBuffer(am.getSoundBuffer("OVERWORLD_NIGHT"));
  bgMusic.play();

  enemyHitSound.setBuffer(am.getSoundBuffer("ENEMY_HIT"));
  enemyKillSound.setBuffer(am.getSoundBuffer("ENEMY_KILL"));
  playerHitSound.setBuffer(am.getSoundBuffer("PLAYER_HIT"));
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
  player->update(dt);
}

void GameState::updateSFMLEvents(sf::RenderTarget* target)
{
  sf::Event e;

  while (window->pollEvent(e))
  {
    if (e.type == sf::Event::Closed)
    {
      window->close();
    }
    if (e.type == sf::Event::KeyPressed)
    {
      if (e.key.code == sf::Keyboard::Escape)
      {
        newState = std::make_unique<MainMenuState>(window, states);
        endState();
      }
      if (e.key.code == sf::Keyboard::P)
      {
        paused = !paused;
      }
    }
  }
}

void GameState::updateItemsInteraction(const float& dt)
{
  itemManager->update(dt);
}

void GameState::updateWorldCollision(const float& dt)
{
  for (auto& it : player->getWeapon()->getBullets())
  {
    const sf::Vector2f& pos = it->getPosition();
    if (!(pos.x > 15 && pos.x < 584 && pos.y > 65 && pos.y < 528))
      it->kill();
  }
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
    enemy->update(dt);

    updateCombat(enemy, index, dt);

    if (enemy->isDead())
    {
      if (rand() % 100 < 30)
        itemManager->createItem(rand() % 4, enemy->getPosition().x, enemy->getPosition().y);

      enemyKillSound.play();
      player->getAttributeComponent()->score += enemy->getGainScore();
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
      float angle = vectorAngle(bullet->getCenter(), enemy->getCenter());
      enemy->move(100.f * cos(angle), 100.f * sin(angle), dt);

      enemyHitSound.play();
      int dmg = 1;
      enemy->loseHP(dmg);
      enemy->resetDamageTimer();
      bullet->kill();
      continue;
    }
  }

  if (enemy->getGlobalBounds().intersects(player->getGlobalBounds()) && player->getDamageTimer())
  {
    playerHitSound.play();
    int dmg = enemy->getAttributeComp()->damageMax;
    player->loseHP(dmg);
  }
}

void GameState::updateEnemySpawner(const float& dt)
{
  int score = player->getAttributeComponent()->score;
  enemySpawner->update(dt);

  if (score >= 0 && score < 300)
    enemySpawner->allowEnemies = { SKELET };
  else if (score >= 300 && score < 2000)
    enemySpawner->allowEnemies = { SKELET, ORC_WARRIOR };
  else if (score >= 2000)
    enemySpawner->allowEnemies = { SKELET, ORC_WARRIOR, BIG_DEMON };

  if (1.f - score / 10000.f >= 0.2f)
    enemySpawner->spawnFactor = 1.f - score / 10000.f;
  else
    enemySpawner->spawnFactor = 0.2f;
}

void GameState::updatePlayerInput(const float& dt)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player->getPosition().x > 15)
    player->move(-1.f, 0.f, dt);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player->getPosition().x < 584)
    player->move(1.f, 0.f, dt);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player->getPosition().y > 65)
    player->move(0.f, -1.f, dt);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player->getPosition().y < 508)
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
    updateWorldCollision(dt);
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
