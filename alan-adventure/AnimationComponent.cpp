#include "stdafx.h"
#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet)
	:sprite(sprite), textureSheet(texture_sheet), lastAnimation(NULL), priorityAnimation(NULL)
{

}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : animations)
	{
		delete i.second;
	}
}

const bool& AnimationComponent::isDone(const std::string key)
{
	return animations[key]->isDone();
}

void AnimationComponent::addAnimation(
	const std::string key,
	float animation_timer,
	int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height
)
{
	animations[key] = new Animation(
		sprite, textureSheet,
		animation_timer,
		start_frame_x, start_frame_y, frames_x, frames_y, width, height
	);
}

const bool& AnimationComponent::play(const std::string key, const float& dt)
{
	if (lastAnimation != animations[key])
	{
		if (lastAnimation == NULL)
			lastAnimation = animations[key];
		else
		{
			lastAnimation->reset();
			lastAnimation = animations[key];
		}
	}

	animations[key]->play(dt);

	return animations[key]->isDone();
}
