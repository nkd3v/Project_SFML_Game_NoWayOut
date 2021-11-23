#pragma once

class Button
{
private:
  sf::Sprite sprite;

public:
  Button();
  ~Button();

  void setPosition(float x, float y);
};

