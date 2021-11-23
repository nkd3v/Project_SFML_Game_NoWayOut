#pragma once

#include "States.h"
#include "TextBox.h"

class EnterNameState :
  public State
{
private:
  sf::Sprite bg;
  sf::Texture bgTexture;

  TextBox nameTextBox;

public:
  EnterNameState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states);
  virtual ~EnterNameState();

  void updateSFMLEvents(sf::RenderTarget* target);
  void updateInput(const float& dt);
  void update(const float& dt, sf::RenderTarget* target);
  void render(sf::RenderTarget* target);
};

