#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class SpriteComponent
{
public:
	SpriteComponent(sf::Texture& texture);
	~SpriteComponent() = default;
public:
	sf::Sprite& GetSprite()
	{
		return m_sprite;
	}
	void Draw(sf::RenderTarget& target);
private:
	sf::Sprite m_sprite;
};

