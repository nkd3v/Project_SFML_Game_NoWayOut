#pragma once

class State
{
protected:
  std::stack<std::unique_ptr<State>>& states;
  sf::RenderWindow* window;
  std::vector<sf::Texture*> textures;

  sf::Vector2i mousePosScreen;
  sf::Vector2i mousePosWindow;
  sf::Vector2f mousePosView;
  sf::Vector2i mousePosGrid;

  int code;

  std::unique_ptr<State> newState;
  bool quit = false;
  bool paused;
  float keytime;
  float keytimeMax;

  bool pressed;

public:
  State(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>& states, int code = 0);
  virtual ~State();

  std::unique_ptr<State>& getNewState();
  const bool& getQuit() const { return quit; }
  const bool getKeytime();

  void endState();
  void pauseState();
  void unpauseState();

  virtual void updateMousePositions(sf::View* view = NULL);
  virtual void updateKeytime(const float& dt);
  virtual void updateSFMLEvents(sf::RenderTarget* target);
  virtual void updateInput(const float& dt) = 0;
  virtual void update(const float& dt, sf::RenderTarget* target) = 0;
  virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

