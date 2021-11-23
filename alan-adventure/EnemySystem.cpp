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

int EnemySystem::getEnemyCount()
{
	return activeEnemies.size();
}

void EnemySystem::createEnemy(const short type, const float xPos, const float yPos)
{
	switch (type)
	{
	case EnemyTypes::SKELET:
		this->activeEnemies.push_back(new Skelet(xPos, yPos, this->textures["SKELET"], this->player));
		break;
	case EnemyTypes::BIG_DEMON:
		this->activeEnemies.push_back(new BigDemon(xPos, yPos, this->textures["BIG_DEMON"], this->player));
		break;
	case EnemyTypes::ORC_WARRIOR:
		this->activeEnemies.push_back(new OrcWarrior(xPos, yPos, this->textures["ORC_WARRIOR"], this->player));
		break;
	default:
		std::cout << "ERROR::ENEMYSYSTEM::CREATEENEMY::TYPE DOES NOT EXIST" << "\n";
		break;
	}
}

void EnemySystem::removeEnemy(const int index)
{
	delete this->activeEnemies[index];
	this->activeEnemies.erase(this->activeEnemies.begin() + index);
}

void EnemySystem::update(const float& dt)
{

}

void EnemySystem::render(sf::RenderTarget* target)
{

}
