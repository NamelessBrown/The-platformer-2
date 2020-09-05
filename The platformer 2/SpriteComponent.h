#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <map>
#include <string>

class Animation
{
public:
	Animation() = default;
	Animation(int numberOfFrames, int x, int y, int width, int height);

	void Apply(sf::Sprite& sprite) const;
	void Update(float dt);
private:
	void Advance();
private:
	static constexpr float m_holdTime = 5.5f;
	float m_time = 0.0f;
	int m_numberOfFrames = 0;
	int m_iFrame = 0;

	std::vector<sf::IntRect> m_frames;
};

class SpriteComponent
{
public:
	SpriteComponent(sf::Texture& texture, const sf::IntRect rect = sf::IntRect(0,0,0,0));
	~SpriteComponent() = default;
public:
	sf::Sprite& GetSprite()
	{
		return m_sprite;
	}
	//No need to call *this if there is no animations
	void Update(float dt);
	void AddAnimation(const std::string& id, const Animation& animation);
	void ChangeAnimation(const std::string& id);
	void Draw(sf::RenderTarget& target);
private:
	sf::Sprite m_sprite;
	std::string m_currentAnimation;
	std::map<std::string, Animation> m_animations;
};

