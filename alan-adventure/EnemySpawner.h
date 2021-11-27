#pragma once

#include "EnemySystem.h"

class EnemySpawner
{
private:
	class SpawnPoint
	{
	public:
		SpawnPoint(sf::Vector2f pos, float minTime, float maxTime)
			: pos(pos), minTime(minTime), maxTime(maxTime)
		{
			nextSpawnTime = rand() % int(maxTime - minTime) + minTime;
		}
		~SpawnPoint() = default;

		sf::Vector2f pos;
		float minTime;
		float maxTime;
		float nextSpawnTime;
	};

	EnemySystem& enemySystem;

	std::vector<std::unique_ptr<SpawnPoint>> spawnPoints;

	sf::Clock clock;

public:
	EnemySpawner(EnemySystem& enemySystem);
	~EnemySpawner();

	int spawnMax;
	std::vector<unsigned int> allowEnemies;
	float spawnFactor;

	void addSpawner(sf::Vector2f pos, float minTime, float maxTime);
	void changeDifficulty(int spawnMax, std::vector<unsigned int> allowEnemies, float spawnFactor);
	void update(const float& dt);
};

