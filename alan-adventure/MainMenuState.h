#pragma once

#include "States.h"

class MainMenuState :
    public State
{
private:
  sf::Text menu[3];
  sf::Font font;
  unsigned int selectedOption;
  int maxOptions;

public:
  MainMenuState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states);
  virtual ~MainMenuState();

  void initMenu();

  void updateMenu();
  void updateInput(const float& dt);

  void update(const float& dt, sf::RenderTarget* target);
  void render(sf::RenderTarget* target);
};

