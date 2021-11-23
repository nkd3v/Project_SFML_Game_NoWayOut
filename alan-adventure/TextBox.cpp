#include "stdafx.h"
#include "TextBox.h"

TextBox::TextBox()
{
  if (!font.loadFromFile("assets/Fonts/dpcomic.ttf"))
    throw("Error: Could not load font");

  text.setFont(font);
  text.setPosition(200.f, 200.f);

  textLimit = 10;
}

TextBox::~TextBox()
{
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
