#include "SpriteComponent.h"
#include <SFML/Graphics/RenderTarget.hpp>

SpriteComponent::SpriteComponent(sf::Texture& texture, const sf::IntRect rect)
	:m_sprite(texture, rect)
{
}

void SpriteComponent::Update(float dt)
{
	m_animations[m_currentAnimation].Update(dt);
	m_animations[m_currentAnimation].Apply(m_sprite);
}

void SpriteComponent::AddAnimation(const std::string& id, const Animation& animation)
{
	m_animations.insert({ id, animation });
}

void SpriteComponent::ChangeAnimation(const std::string& id)
{
	m_currentAnimation = id;
}

void SpriteComponent::Draw(sf::RenderTarget& target)
{
	target.draw(m_sprite);
}

Animation::Animation(int numberOfFrames, int x, int y, int width, int height)
	:m_numberOfFrames(numberOfFrames), m_frames(numberOfFrames)
{
	for (unsigned i = 0; i < m_frames.size(); i++)
	{
		m_frames[i] = sf::IntRect(x + i * width, y, width, height);
	}

}

void Animation::Apply(sf::Sprite& sprite) const
{
	sprite.setTextureRect(m_frames[m_iFrame]);
}

void Animation::Update(float dt)
{
	m_time += dt;

	while (m_time > m_holdTime)
	{
		m_time -= m_holdTime;
		Advance();
	}
}

void Animation::Advance()
{
	if (++m_iFrame >= m_numberOfFrames)
	{
		m_iFrame = 0;
	}
}

