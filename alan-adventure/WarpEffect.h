#pragma once
#include "Buff.h"
#include "AnimationComponent.h"

class WarpEffect :
    public Buff
{
private:

  sf::Sprite sprite;
  AnimationComponent* animationComponent;

public:
  WarpEffect(float lifetimeMax, Entity& entity);
  ~WarpEffect();

  void update();
  bool endOfLife();
  void render(sf::RenderTarget& target);
};

