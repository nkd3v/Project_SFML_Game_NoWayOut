#include "stdafx.h"
#include "ItemManager.h"

ItemManager::ItemManager(std::vector<Item*>& items,
	std::map<std::string, sf::Texture>& textures, Player& player, BuffManager *buffManager)
	: textures(textures), items(items), player(player), buffManager(buffManager)
{
	itemPickSound.setBuffer(am.getSoundBuffer("ITEM_PICK"));
}

ItemManager::~ItemManager()
{

}

int ItemManager::getItemCount()
{
	return 4;
}

void ItemManager::createItem(const short type, const float xPos, const float yPos)
{
	switch (type)
	{
	case ItemTypes::HEALTH_POTION:
		this->items.push_back(new HealthPotion(xPos, yPos, this->textures["HEALTH_POTION"], this->player));
		break;
	case ItemTypes::RAPID_FIRE_POTION:
		this->items.push_back(new RapidFirePotion(xPos, yPos, this->textures["RAPID_FIRE_POTION"], this->player));
		break;
	case ItemTypes::SWIFT_POTION:
		this->items.push_back(new SwiftPotion(xPos, yPos, this->textures["SWIFT_POTION"], this->player, buffManager));
		break;
	case ItemTypes::INVISIBLE_POTION:
		this->items.push_back(new InvisiblePotion(xPos, yPos, this->textures["INVISIBLE_POTION"], this->player));
		break;
	default:
		throw("Error: Enemy type does not exists");
		break;
	}
}

void ItemManager::removeItem(const int index)
{
	delete this->items[index];
	this->items.erase(this->items.begin() + index);
}

void ItemManager::update(const float& dt, BuffManager* buffManager)
{
	for (auto& item : items)
	{
		item->update(dt);
	}

	for (auto it = items.begin(); it != items.end();)
	{
		if ((*it)->getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			itemPickSound.play();
			player.getAttributeComponent()->score += 20;
			(*it)->activate();
			it = items.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void ItemManager::render(sf::RenderTarget* target)
{
	for (auto& item : items)
	{
		item->render(*target);
	}
}
