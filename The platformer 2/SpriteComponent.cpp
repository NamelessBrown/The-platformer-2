#include "SpriteComponent.h"
#include <SFML/Graphics/RenderTarget.hpp>

SpriteComponent::SpriteComponent(sf::Texture& texture)
	:m_sprite(texture)
{
}

void SpriteComponent::Draw(sf::RenderTarget& target)
{
	target.draw(m_sprite);
}
