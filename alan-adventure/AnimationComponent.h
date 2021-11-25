#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

class AnimationComponent
{
private:
	class Animation
	{
	public:
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float animationTimer;
		float timer;
		bool done;
		int width;
		int height;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;

		Animation(sf::Sprite& sprite, sf::Texture& textureSheet,
			float animationTimer,
			int startFrameX, int startFrameY, int framesX, int framesY, int width, int height)
			:
			sprite(sprite), textureSheet(textureSheet),
			animationTimer(animationTimer),
			timer(0.f),
			done(false),
			width(width),
			height(height)
		{
			startRect = sf::IntRect(startFrameX * width, startFrameY * height, width, height);
			currentRect = startRect;
			endRect = sf::IntRect(framesX * width, framesY * height, width, height);

			sprite.setTexture(textureSheet, true);
			sprite.setTextureRect(startRect);
		}

		const bool& isDone() const
		{
			return done;
		}

		const bool& play(const float& dt)
		{
			done = false;
			timer += 100.f * dt;
			if (timer >= animationTimer)
			{
				timer = 0.f;

				if (currentRect != endRect)
				{
					currentRect.left += width;
				}
				else
				{
					currentRect.left = startRect.left;
					done = true;
				}

				sprite.setTextureRect(currentRect);
			}

			return done;
		}

		void reset()
		{
			timer = animationTimer;
			currentRect = startRect;
		}
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;
	Animation* lastAnimation;
	Animation* priorityAnimation;

public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
	virtual ~AnimationComponent();

	const bool& isDone(const std::string key);

	void addAnimation(const std::string key,
		float animationTimer,
		int startFrameX, int startFrameY, int framesX, int framesY, int width, int height);

	const bool& play(const std::string key, const float& dt);
};

#endif
