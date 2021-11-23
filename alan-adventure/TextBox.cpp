#include "stdafx.h"
#include "TextBox.h"

TextBox::TextBox()
{
  if (!font.loadFromFile("assets/Fonts/dpcomic.ttf"))
    throw("Error: Could not load font");

  text.setFont(font);

  textLimit = 16;
}

TextBox::~TextBox()
{
}

void TextBox::setPosition(float x, float y)
{
  text.setPosition(x, y);
}

void TextBox::setCharacterSize(unsigned int size)
{
  text.setCharacterSize(size);
}

std::string TextBox::getString()
{
  return str;
}

void TextBox::update(char c)
{
  if (c >= 20 && c < 127 && str.getSize() < textLimit)
    str += c;
  else if (c == DELETE_KEY && !str.isEmpty())
    str.erase(str.getSize() - 1);

  text.setString(str);
}

void TextBox::render(sf::RenderTarget& target)
{
  target.draw(text);
}
