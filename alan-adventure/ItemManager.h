#pragma once

#include "BuffManager.h"
#include "HealthPotion.h"
#include "RapidFirePotion.h"
#include "SwiftPotion.h"
#include "InvisiblePotion.h"

enum ItemTypes { HEALTH_POTION, RAPID_FIRE_POTION, SWIFT_POTION, INVISIBLE_POTION };

class ItemManager
{
private:
	std::map<std::string, sf::Texture>& textures;
	std::vector<Item*>& items;
	Player& player;
	BuffManager* buffManager;

	sf::Sound itemPickSound;

public:
	ItemManager(std::vector<Item*>& items,
		std::map<std::string, sf::Texture>& textures, Player& player, BuffManager* buffManager);
	virtual ~ItemManager();

	int getItemCount();

	void createItem(const short type, const float xPos, const float yPos);
	void removeItem(const int index);

	void update(const float& dt, BuffManager* buffManager);
	void render(sf::RenderTarget* target);
};

