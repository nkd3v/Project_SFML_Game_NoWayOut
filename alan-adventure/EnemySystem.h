#ifndef ENEMYSYSTEM_H
#define ENEMYSYSTEM_H

#include "Skelet.h"
#include "BigDemon.h"
#include "OrcWarrior.h"
#include "Necromancer.h"

enum EnemyTypes { SKELET, BIG_DEMON, ORC_WARRIOR, NECROMANCER };

class EnemySystem
{
private:
	std::map<std::string, sf::Texture>& textures;
	std::vector<Enemy*>& activeEnemies;
	Entity& player;

public:
	EnemySystem(std::vector<Enemy*>& activeEnemies,
		std::map<std::string, sf::Texture>& textures, Entity& player);
	virtual ~EnemySystem();

	int getEnemyTypeSize();
	int getActiveEnemies();

	void createEnemy(const short type, const float xPos, const float yPos);
	void removeEnemy(const int index);

	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

#endif //!ENEMYSYSTEM_H