#include "stdafx.h"
#include "Game.h"

void Game::initWindow()
{
  window = new sf::RenderWindow(sf::VideoMode(800, 800), "No Way Out", sf::Style::Close);
  window->setFramerateLimit(120);
  window->setVerticalSyncEnabled(false);

  icon = am.getImage("FAVICON");

  window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Game::initStates()
{
  states.emplace(std::make_unique<MainMenuState>(window, states));
}

void Game::initResources()
{
  am.loadFont("DPCOMIC", "assets/Fonts/dpcomic.ttf");

  am.loadSoundBuffer("TITLE_SCREEN", "assets/Sounds/Music/title-screen.wav");
  am.loadSoundBuffer("OVERWORLD_NIGHT", "assets/Sounds/Music/overworld-night.wav");
  am.loadSoundBuffer("JUNGLE", "assets/Sounds/Music/jungle.wav");
  am.loadSoundBuffer("DUNGEON", "assets/Sounds/Music/dungeon.wav");
  am.loadSoundBuffer("GRAVEYARD", "assets/Sounds/Music/graveyard.wav");
  am.loadSoundBuffer("APHEX", "assets/Sounds/Music/aphex.wav");

  am.loadSoundBuffer("ENEMY_HIT", "assets/Sounds/enemy-hit.wav");
  am.loadSoundBuffer("ENEMY_KILL", "assets/Sounds/enemy-kill.wav");
  am.loadSoundBuffer("ITEM_PICK", "assets/Sounds/item-pick.wav");
  am.loadSoundBuffer("PLAYER_HIT", "assets/Sounds/player-hit.wav");
  am.loadSoundBuffer("SHOOT_ARROW", "assets/Sounds/shoot-arrow.wav");

  am.loadImage("FAVICON", "assets/favicon.png");

  am.loadTexture("NECROMANCER", "assets/Enemy/necromancer.png");
  am.loadTexture("BULLET", "assets/Weapon/arrow.png");
  am.loadTexture("FIREBALL", "assets/Weapon/fireball.png");
  am.loadTexture("BOW", "assets/Weapon/bow.png");
  am.loadTexture("BLOOD_SPLAT", "assets/Effects/blood-splat.png");

  am.loadTexture("WARP", "assets/Effects/warp.png");
}

Game::Game()
{
  initResources();
  initWindow();
  initStates();
}

Game::~Game()
{
  delete window;

  while (!states.empty())
  {
    states.pop();
  }
}

sf::RenderWindow& Game::getWindow()
{
  return *window;
}

void Game::update()
{
  if (!this->states.empty())
  {
    this->states.top()->update(this->dt, window);

    if (this->states.top()->getQuit())
    {
      std::unique_ptr<State> newState;
      if (states.top()->getNewState() != NULL)
        newState = std::move(states.top()->getNewState());

      states.top()->endState();
      states.pop();

      if (newState != NULL)
        states.push(std::move(newState));
    }
  }

  if (states.empty())
    window->close();
}

void Game::updateDt()
{
  dt = dtClock.restart().asSeconds();
  Time.deltaTime = dt;
}

void Game::run()
{
  while (window->isOpen())
  {
    updateDt();
    update();
    render();
  }
}

void Game::render()
{
  window->clear();

  if (!states.empty())
    states.top()->render(window);

  window->display();
}
