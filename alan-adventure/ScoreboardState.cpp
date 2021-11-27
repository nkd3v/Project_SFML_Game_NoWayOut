#include "stdafx.h"
#include "ScoreboardState.h"

ScoreboardState::ScoreboardState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states, int code)
  : State(window, states, code)
{
  if (!font.loadFromFile("assets/Fonts/dpcomic.ttf"))
    throw "Error: Could not load font";

  if (!bgTexture.loadFromFile("assets/GUI/menu-bg.png"))
    throw "Error: Could not load background";

  bg.setTexture(bgTexture);

  text.setFont(font);

  if (code > 0)
  {
    nameEntered = false;
  }
  else
  {
    nameEntered = true;
    scores = scoreboard.getScores();
  }

  nameTextBox.setPosition(300, 200);
  nameTextBox.setCharacterSize(42);
}

ScoreboardState::~ScoreboardState()
{
}

void ScoreboardState::saveScore()
{
  scoreboard.addScore(playerName, code);
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
      window->close();

    if (e.type == sf::Event::KeyPressed)
    {
      if (e.key.code == sf::Keyboard::Escape)
      {
        newState = std::make_unique<MainMenuState>(window, states);
        endState();
      }

      if (!nameEntered)
      {
        if (e.key.code == sf::Keyboard::Enter)
        {
          playerName = nameTextBox.getString();
          nameEntered = true;
          saveScore();
          scores = scoreboard.getScores();
        }
      }
      else
      {
        if (e.key.code == sf::Keyboard::Enter)
        {
          newState = std::make_unique<MainMenuState>(window, states);
          endState();
        }
      }
    }

    if (!nameEntered)
    {
      if (e.type == sf::Event::TextEntered)
        nameTextBox.update(static_cast<char>(e.text.unicode));
    }
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
      text.setPosition(200, static_cast<float>(180 + i * 70));
      text.setString(scores[i].second);
      target->draw(text);

      text.setPosition(600, static_cast<float>(180 + i * 70));
      text.setString(std::to_string(scores[i].first));
      target->draw(text);
    }
  }
}