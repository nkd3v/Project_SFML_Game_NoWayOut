#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <memory>
#include <map>
#include <stack>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class State
{
protected:
  sf::RenderWindow* window;
  std::vector<sf::Texture*> textures;

  bool quit = false;

public:
  State(sf::RenderWindow* window);
  virtual ~State();

  const bool& getQuit() const { return quit; }

  virtual void update(const float& dt) = 0;
  virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

