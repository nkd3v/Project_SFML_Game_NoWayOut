#pragma once
#include "Buff.h"

class BloodSplat :
  public Buff
{
private:

  sf::Sprite sprite;

public:
  BloodSplat(float lifetimeMax, Entity& entity, sf::Vector2f pos = sf::Vector2f());
  ~BloodSplat();

  void render(sf::RenderTarget& target);
};

