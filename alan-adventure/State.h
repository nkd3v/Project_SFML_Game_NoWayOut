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

  sf::Vector2i mousePosScreen;
  sf::Vector2i mousePosWindow;
  sf::Vector2f mousePosView;
  sf::Vector2i mousePosGrid;
  
  bool quit = false;
  bool paused;
  float keytime;
  float keytimeMax;

public:
  State(sf::RenderWindow* window);
  virtual ~State();

  const bool& getQuit() const { return quit; }

  void endState();
  void pauseState();
  void unpauseState();

  virtual void updateMousePositions(sf::View* view = NULL);
  virtual void updateKeytime(const float& dt);
  virtual void updateInput(const float& dt) = 0;
  virtual void update(const float& dt) = 0;
  virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

