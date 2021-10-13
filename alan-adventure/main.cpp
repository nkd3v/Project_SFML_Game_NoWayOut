#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Enemy.h"
#include <memory>
#include <iostream>

static const unsigned int SCREEN_HEIGHT = 800;
static const unsigned int SCREEN_WIDTH = 800;

void ResizeView(const sf::RenderWindow &window, sf::View &view)
{
  float aspectRatio = float(window.getSize().x / float(window.getSize().y));
  view.setSize(SCREEN_HEIGHT * aspectRatio, SCREEN_HEIGHT);  
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Alan's Adventure");
  sf::View view(sf::Vector2f(765.0f, 408.0f), sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
  window.setView(view);

  sf::Texture playerTexture;
  playerTexture.loadFromFile("assets/Character/Character.png");

  Player player(&playerTexture, sf::Vector2u(4, 4), 0.2f, 200.0f);
  player.SetPosition(sf::Vector2f(765.0f, 408.0f));

  sf::Texture enemyTexture;
  enemyTexture.loadFromFile("assets/Enemy/Enemy01.png");
  Enemy enemy(&enemyTexture, sf::Vector2u(4, 4), 0.2f, 100.0f, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(765.0f, 408.0f));
  enemy.SetTarget(&player.body);

  sf::Texture mapTexture;
  mapTexture.loadFromFile("assets/Maps/01.png");
  sf::Sprite map(mapTexture);
  map.setScale(sf::Vector2f(0.8f, 0.8f));

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

    // enemy.GetCollider().CheckCollision(player.GetCollider(), sf::Vector2f(0.0f, 0.0f), 1.0f);
    //bool hit = player.GetCollider().CheckCollision(enemy.GetCollider(), sf::Vector2f(0.0f, 0.0f), 0.0f);

    //if (hit)
    //{
    //  player.TakeDamage(1);
    //  player.SetPosition(player.GetPosition() + sf::Vector2f(0.0f, 20.0f));
    //}
    player.Update(deltaTime, window);
    enemy.Update(deltaTime);
    // view.setCenter(player.GetPosition());
    // sf::Vector2f mousePos(sf::Mouse::getPosition(window));
    // player.setPosition(mousePos);
    window.clear();
    window.setView(view);
    window.draw(map);
    player.Draw(window);
    enemy.Draw(window);
    window.display();
    //std::cout << player.GetPosition().x << ' ' << player.GetPosition().y << '\n';
    // std::cout << sf::Mouse::getPosition(window).x << ' ' << sf::Mouse::getPosition(window).y << '\n';
  }

  return 0;
}