#pragma once

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

class Animation
{
public:
	void AddFrame(sf::IntRect rect);
	void SetSpriteSheet(const sf::Texture& texture);
	const sf::Texture* GetSpriteSheet() const;
	size_t GetSize() const;
	const sf::IntRect& GetFrame(size_t n) const;
private:
	std::vector<sf::IntRect> m_frames;
	const sf::Texture* m_texture = nullptr;
};

