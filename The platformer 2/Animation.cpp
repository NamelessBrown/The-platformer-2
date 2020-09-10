#include "Animation.h"

void Animation::AddFrame(sf::IntRect rect)
{
	m_frames.push_back(rect);
}

void Animation::SetSpriteSheet(const sf::Texture& texture)
{
	m_texture = &texture;
}

const sf::Texture* Animation::GetSpriteSheet() const
{
	return m_texture;
}

size_t Animation::GetSize() const
{
	return m_frames.size();
}

const sf::IntRect& Animation::GetFrame(size_t n) const
{
	return m_frames[n];
}
