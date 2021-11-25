#pragma once

#include "States.h"

class MainMenuState :
    public State
{
private:
  sf::Text titleText;
  sf::Text nameText;

  sf::Text menu[3];
  sf::Font font;
  
  sf::Texture bgTexture;
  sf::Sprite bg;

  unsigned int selectedOption;
  int maxOptions;

  sf::SoundBuffer bgMusicBuffer;
  sf::Sound bgMusic;

public:
  MainMenuState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states);
  virtual ~MainMenuState();

  void initMenu();

  void updateMenu();
  void updateSFMLEvents(sf::RenderTarget* target);
  void updateInput(const float& dt);

  void changeState();

  void update(const float& dt, sf::RenderTarget* target);
  void render(sf::RenderTarget* target);
};

