#include "stdafx.h"
#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(EnemySystem& enemySystem)
  : enemySystem(enemySystem)
{
  spawnMax = 10;
  spawnFactor = 1.f;
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::addSpawner(sf::Vector2f pos, float minTime, float maxTime)
{
  spawnPoints.push_back(std::make_unique<SpawnPoint>(pos, minTime, maxTime));
}

void EnemySpawner::changeDifficulty(int newSpawnMax, std::vector<unsigned int> newAllowEnemies, float newSpawnFactor)
{
  this->spawnMax = newSpawnMax;
  this->allowEnemies = std::move(newAllowEnemies);
  this->spawnFactor = newSpawnFactor;
}

void EnemySpawner::update(const float& dt)
{

  for (auto& spawnPoint : spawnPoints)
  {
    if (enemySystem.getActiveEnemies() >= spawnMax)
      return;

    if (clock.getElapsedTime().asSeconds() >= spawnPoint->nextSpawnTime)
    {
      enemySystem.createEnemy(allowEnemies[static_cast<unsigned int>(rand() % allowEnemies.size())], spawnPoint->pos.x, spawnPoint->pos.y);
      spawnPoint->nextSpawnTime =
        clock.getElapsedTime().asSeconds()
        + (rand() % int(spawnPoint->maxTime - spawnPoint->minTime)
          + spawnPoint->minTime)
        * spawnFactor;
    }
  }
}
