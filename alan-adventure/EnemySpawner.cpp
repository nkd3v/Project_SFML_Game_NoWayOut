#include "stdafx.h"
#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(EnemySystem& enemySystem)
  : enemySystem(enemySystem)
{
  spawnMax = 3;
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::addSpawner(sf::Vector2f pos, float minTime, float maxTime)
{
  spawnPoints.push_back(std::make_unique<SpawnPoint>(pos, minTime, maxTime));
}

void EnemySpawner::update(const float& dt)
{

  for (auto& spawnPoint : spawnPoints)
  {
    if (enemySystem.getEnemyCount() >= spawnMax)
      return;

    if (clock.getElapsedTime().asSeconds() >= spawnPoint->nextSpawnTime)
    {
      enemySystem.createEnemy(rand() % 3, spawnPoint->pos.x, spawnPoint->pos.y);
      spawnPoint->nextSpawnTime = clock.getElapsedTime().asSeconds()
                               + rand() % int(spawnPoint->maxTime - spawnPoint->minTime)
                               + spawnPoint->minTime;
    }
  }
}
