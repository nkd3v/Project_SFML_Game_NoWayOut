#include "stdafx.h"
#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
  : State(window)
{
  initTextures();
  initEnemySystem();
  initView();

  initPlayers();
}

GameState::~GameState()
{
  delete player;
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
}

void GameState::initPlayers()
{
  player = new Player(50, 50, textures["PLAYER_SHEET"]);
}

void GameState::initEnemySystem()
{
  this->enemySystem = new EnemySystem(this->activeEnemies, this->textures, *this->player);
}

void GameState::initView()
{
  view.setSize(1280.f, 720.f);
  view.setCenter(1280.f / 2.f, 720.f / 2.f);
  view.zoom(2.f);
}

void GameState::updateInput(const float& dt)
{

}

void GameState::updatePlayer(const float& dt)
{
  player->update(dt, mousePosView, view);
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
  }
}

void GameState::render(sf::RenderTarget* target)
{
  if (!target)
    target = window;

  player->render(*target);
}
