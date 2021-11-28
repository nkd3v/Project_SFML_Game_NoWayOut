#include "stdafx.h"
#include "WarpEffect.h"

WarpEffect::WarpEffect(float lifetimeMax, Entity& entity)
  : Buff(lifetimeMax, entity)
{
  name = "Warp effect";

  sprite.setPosition(entity.getPosition());

  animationComponent = new AnimationComponent(sprite, am.getTexture("WARP"));
  animationComponent->addAnimation("IDLE", 16.f, 0, 0, 6, 0, 36, 32);
  animationComponent->play("IDLE", Time.deltaTime);
}

WarpEffect::~WarpEffect()
{
  delete animationComponent;
}

void WarpEffect::update()
{
  animationComponent->play("IDLE", Time.deltaTime);
}

bool WarpEffect::endOfLife()
{
  return animationComponent->isDone("IDLE");
}

void WarpEffect::render(sf::RenderTarget& target)
{
  target.draw(sprite);
}
