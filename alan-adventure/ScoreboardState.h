#pragma once

#include "States.h"
#include "TextBox.h"
#include "Scoreboard.h"

class ScoreboardState :
  public State
{
private:
  sf::Font font;
  sf::Text text;

  TextBox nameTextBox;

  sf::Sprite bg;
  sf::Texture bgTexture;

  Scoreboard scoreboard;
  std::vector<std::pair<int, std::string>> scores;

public:
  ScoreboardState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states);
  virtual ~ScoreboardState();

  void updateInput(const float& dt);
  void updateSFMLEvents(sf::RenderTarget* target);
  void update(const float& dt, sf::RenderTarget* target);
  void render(sf::RenderTarget* target);
};

