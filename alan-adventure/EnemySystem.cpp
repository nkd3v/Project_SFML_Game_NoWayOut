#include "stdafx.h"
#include "EnemySystem.h"

EnemySystem::EnemySystem(std::vector<Enemy*>& activeEnemies,
	std::map<std::string, sf::Texture>& textures, Entity& player)
	: textures(textures), activeEnemies(activeEnemies), player(player)
{

}

EnemySystem::~EnemySystem()
{

}

int EnemySystem::getEnemyTypeSize()
{
	return 4;
}

void EnemySystem::createEnemy(const short type, const float xPos, const float yPos)
{
	switch (type)
	{
	case EnemyTypes::SKELET:
		activeEnemies.push_back(new Skelet(xPos, yPos, textures["SKELET"], player));
		break;
	case EnemyTypes::BIG_DEMON:
		activeEnemies.push_back(new BigDemon(xPos, yPos, textures["BIG_DEMON"], player));
		break;
	case EnemyTypes::ORC_WARRIOR:
		activeEnemies.push_back(new OrcWarrior(xPos, yPos, textures["ORC_WARRIOR"], player));
		break;
	case EnemyTypes::NECROMANCER:
		activeEnemies.push_back(new Necromancer(xPos, yPos, am.getTexture("NECROMANCER"), player));
	}
}

void EnemySystem::removeEnemy(const int index)
{
	delete activeEnemies[index];
	activeEnemies.erase(activeEnemies.begin() + index);
}

void EnemySystem::update(const float& dt)
{

}

void EnemySystem::render(sf::RenderTarget* target)
{

}
