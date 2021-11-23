#pragma once

constexpr int DELETE_KEY = 8;
constexpr int ENTER_KEY = 13;
constexpr int ESCAPE_KEY = 27;

class TextBox
{
private:
  sf::Text text;
  sf::Font font;
  sf::String str;

  int textLimit;

public:
  TextBox();
  ~TextBox();
  
  void update(char c);
  void render(sf::RenderTarget& target);
};

