#include "stdafx.h"
#include "ScoreboardState.h"

ScoreboardState::ScoreboardState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states)
  : State(window, states)
{
  if (!font.loadFromFile("assets/Fonts/dpcomic.ttf"))
    throw "Error: Could not load font";

  if (!bgTexture.loadFromFile("assets/GUI/menu-bg.png"))
    throw "Error: Could not load background";

  bg.setTexture(bgTexture);

  text.setFont(font);

  scores = std::move(scoreboard.getScores());
}

ScoreboardState::~ScoreboardState()
{
}

void ScoreboardState::updateInput(const float& dt)
{
  
}

void ScoreboardState::updateSFMLEvents(sf::RenderTarget* target)
{
  sf::Event e;
  while (window->pollEvent(e))
  {
    if (e.type == sf::Event::Closed)
    {
      window->close();
    }
    else if (e.type == sf::Event::TextEntered)
    {
      nameTextBox.update(e.text.unicode);
    }
  }
}

void ScoreboardState::update(const float& dt, sf::RenderTarget* target)
{
  updateSFMLEvents(target);
  updateInput(dt);
}

void ScoreboardState::render(sf::RenderTarget* target = nullptr)
{
  target->draw(bg);
  target->draw(text);
  nameTextBox.render(*target);

  text.setString("Scoreboard");
  text.setPosition(250, 60);
  text.setCharacterSize(72);
  target->draw(text);

  text.setCharacterSize(42);
  for (int i = 0; i < scores.size(); i++)
  {
    text.setPosition(200, 180 + i * 70);
    text.setString(scores[i].second);
    target->draw(text);

    text.setPosition(600, 180 + i * 70);
    text.setString(std::to_string(scores[i].first));
    target->draw(text);
  }
}