#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Platform.h"

static const float SCREEN_HEIGHT = 512.0f;
static const float SCREEN_WIDTH = 512.0f;

void ResizeView(const sf::RenderWindow &window, sf::View &view)
{
  float aspectRatio = float(window.getSize().x / float(window.getSize().y));
  view.setSize(SCREEN_HEIGHT * aspectRatio, SCREEN_HEIGHT);  
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
  sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));

  sf::Texture playerTexture;
  playerTexture.loadFromFile("./assets/Character/Character.png");

  Player player(&playerTexture, sf::Vector2u(4, 4), 0.2f, 200.0f);
  Platform platform1(nullptr, sf::Vector2f(200.0f, 200.0f), sf::Vector2f(200.0f, 0.0f));

  float deltaTime = 0.0f;
  sf::Clock clock;

  while (window.isOpen())
  {
    deltaTime = clock.restart().asSeconds();

    sf::Event event;
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::TextEntered:
        putchar(event.text.unicode);
        break;

      case sf::Event::Resized:
        ResizeView(window, view);
        break;
      }
    }

    // platform1.GetCollider().CheckCollision(player.GetCollider(), sf::Vector2f(0.0f, 0.0f), 1.0f);
    player.GetCollider().CheckCollision(platform1.GetCollider(), sf::Vector2f(0.0f, 0.0f), 0.0f);

    player.Update(deltaTime);
    view.setCenter(player.GetPosition());
    // sf::Vector2f mousePos(sf::Mouse::getPosition(window));
    // player.setPosition(mousePos);
    window.clear(sf::Color::Magenta);
    platform1.Draw(window);
    // window.setView(view);
    player.Draw(window);
    window.display();
  }

  return 0;
}