#pragma once

#include "SFML/Graphics.hpp"

class Game
{
private:
	// Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	// Initialization
	void initVariables();

public:
	// Constructor and destructor
	Game();
	virtual ~Game();

	// Methods
	void update();
	void updateDt();
	void updateSFMLEvents();
	void run();
	void render();
};

