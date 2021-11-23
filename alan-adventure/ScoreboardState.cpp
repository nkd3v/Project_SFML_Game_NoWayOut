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

  nameEntered = false;
  nameTextBox.setPosition(300, 200);
  nameTextBox.setCharacterSize(42);
}

ScoreboardState::~ScoreboardState()
{
}

void ScoreboardState::saveScore()
{
  scoreboard.addScore(playerName, 69);
}

void ScoreboardState::updateInput(const float& dt)
{
  if (!getKeytime()) return;

  if (!nameEntered)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
      playerName = std::move(nameTextBox.getString());
      nameEntered = true;
      saveScore();
      scores = std::move(scoreboard.getScores());
    }
  }
  else
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
      newState = std::make_unique<MainMenuState>(window, states);
      quit = true;
    }
  }
}

void ScoreboardState::updateSFMLEvents(sf::RenderTarget* target)
{
  sf::Event e;
  while (window->pollEvent(e))
  {
    if (e.type == sf::Event::Closed)
      window->close();

    if (!nameEntered)
      if (e.type == sf::Event::TextEntered)
        nameTextBox.update(e.text.unicode);
  }
}

void ScoreboardState::update(const float& dt, sf::RenderTarget* target)
{
  updateKeytime(dt);
  updateMousePositions();
  updateSFMLEvents(target);
  updateInput(dt);
}

void ScoreboardState::render(sf::RenderTarget* target = nullptr)
{
  target->clear(sf::Color(128, 128, 128, 255));

  target->draw(bg);
  target->draw(text);

  if (!nameEntered)
  {
    text.setString("Enter your name");
    text.setPosition(170, 60);
  }
  else
  {
    text.setString("Scoreboard");
    text.setPosition(250, 60);
  }

  text.setCharacterSize(72);
  target->draw(text);

  if (!nameEntered)
  {
    nameTextBox.render(*target);
  }
  else
  {
    text.setCharacterSize(42);

    for (size_t i = 0; i < scores.size(); i++)
    {
      text.setPosition(200, 180 + i * 70);
      text.setString(scores[i].second);
      target->draw(text);

      text.setPosition(600, 180 + i * 70);
      text.setString(std::to_string(scores[i].first));
      target->draw(text);
    }
  }
}