#include "Goal.h"

Goal::Goal(sf::Texture& texture)
	:m_sprite(texture)
{
	m_sprite.setScale(m_sprite.getScale() / 4.f);
}

void Goal::SetPosition(const sf::Vector2f& position)
{
	SetPosition(position.x, position.y);
}

void Goal::SetPosition(float x, float y)
{
	m_sprite.setPosition(x, y);
}

void Goal::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite);
}
