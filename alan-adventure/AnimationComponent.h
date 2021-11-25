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

		//Accessor
		const bool& isDone() const
		{
			return done;
		}

		//Functions
		const bool& play(const float& dt)
		{
			//Update timer
			done = false;
			timer += 100.f * dt;
			if (timer >= animationTimer)
			{
				//reset timer
				timer = 0.f;

				//Animate
				if (currentRect != endRect)
				{
					currentRect.left += width;
				}
				else //Reset
				{
					currentRect.left = startRect.left;
					done = true;
				}

				sprite.setTextureRect(currentRect);
			}

			return done;
		}

		const bool& play(const float& dt, float mod_percent)
		{
			//Update timer
			if (mod_percent < 0.5f)
				mod_percent = 0.5f;

			done = false;
			timer += mod_percent * 100.f * dt;
			if (timer >= animationTimer)
			{
				//reset timer
				timer = 0.f;

				//Animate
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

	//Accessor
	const bool& isDone(const std::string key);

	//Functions
	void addAnimation(const std::string key,
		float animationTimer,
		int startFrameX, int startFrameY, int framesX, int framesY, int width, int height);

	const bool& play(const std::string key, const float& dt, const bool priority = false);
	const bool& play(const std::string key, const float& dt, const float& modifier, const float& modifier_max, const bool priority = false);
};

#endif
