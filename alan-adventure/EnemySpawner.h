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
	int spawnMax;

public:
	EnemySpawner(EnemySystem& enemySystem);
	~EnemySpawner();

	void addSpawner(sf::Vector2f pos, float minTime, float maxTime);
	void update(const float& dt);
};

