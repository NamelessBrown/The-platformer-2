#include "AnimatedSprite.h"
#include <cmath>

AnimatedSprite::AnimatedSprite(sf::Time frameTime, bool paused, bool loop)
	:m_animation(nullptr), m_texture(nullptr), m_frameTime(frameTime), m_currentFrame(0), m_isPaused(paused),
	m_isLooped(loop)
{
}

void AnimatedSprite::Update(sf::Time deltaTime)
{
	if (!m_isPaused && m_animation)
	{
		m_currentTime += deltaTime;

		if (m_currentTime > m_frameTime)
		{
			m_currentTime = sf::microseconds(m_currentTime.asMicroseconds() % m_frameTime.asMicroseconds());

			if (m_currentFrame + 1 < m_animation->GetSize())
			{
				m_currentFrame++;
			}
			else
			{
				// animation has ended
				if (!m_isLooped)
				{
					m_isPaused = true;
				}
				else
				{
					m_currentFrame = 0; // reset to start
				}
			}

			SetFrame(m_currentFrame, false);
		}
	}
}

void AnimatedSprite::SetAnimation(const Animation& animation)
{
	m_animation = &animation;
	m_texture = m_animation->GetSpriteSheet();
	m_currentFrame = 0;
	SetFrame(m_currentFrame);
}

void AnimatedSprite::SetFrameTime(sf::Time time)
{
	m_frameTime = time;
}

void AnimatedSprite::Play()
{
	m_isPaused = false;
}

void AnimatedSprite::Play(const Animation& animation)
{
	if (GetAnimation() != &animation)
	{
		SetAnimation(animation);
	}
	Play();
}

void AnimatedSprite::Pause()
{
	m_isPaused = true;
}

void AnimatedSprite::Stop()
{
	m_isPaused = true;
	m_currentFrame = 0;
	SetFrame(m_currentFrame);
}

void AnimatedSprite::SetLooped(bool looped)
{
	m_isLooped = looped;
}

void AnimatedSprite::SetColor(const sf::Color& color)
{
	m_vertices[0].color = color;
	m_vertices[1].color = color;
	m_vertices[2].color = color;
	m_vertices[3].color = color;
}

const Animation* AnimatedSprite::GetAnimation() const
{
	return m_animation;
}

sf::FloatRect AnimatedSprite::GetLocalBounds() const
{
	sf::IntRect rect = m_animation->GetFrame(m_currentFrame);
	float width = (float)std::abs(rect.width);
	float height = (float)std::abs(rect.height);


	return sf::FloatRect(0.f, 0.f, width, height);
}

sf::FloatRect AnimatedSprite::GetGlobalBounds() const
{
	return getTransform().transformRect(GetLocalBounds());
}

bool AnimatedSprite::IsLooped() const
{
	return m_isLooped;
}

bool AnimatedSprite::IsPlaying() const
{
	return !m_isPaused;
}

sf::Time AnimatedSprite::GetFrameTime() const
{
	return m_frameTime;
}

void AnimatedSprite::SetFrame(std::size_t newFrame, bool resetTime)
{
	if (m_animation)
	{
		sf::IntRect rect = m_animation->GetFrame(newFrame);

		m_vertices[0].position = sf::Vector2f(0.f, 0.f);
		m_vertices[1].position = sf::Vector2f(0.f, float(rect.height));
		m_vertices[2].position = sf::Vector2f(float(rect.width), float(rect.height));
		m_vertices[3].position = sf::Vector2f(float(rect.width), 0.f);

		float left = float(rect.left) + 0.0001f;
		float right = left + float(rect.width);
		float top = float(rect.top);
		float bottom = top + float(rect.height);

		m_vertices[0].texCoords = sf::Vector2f(left, top);
		m_vertices[1].texCoords = sf::Vector2f(left, bottom);
		m_vertices[2].texCoords = sf::Vector2f(right, bottom);
		m_vertices[3].texCoords = sf::Vector2f(right, top);

	}

	if (resetTime)
	{
		m_currentTime = sf::Time::Zero;
	}

}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_animation && m_texture)
	{
		states.transform = getTransform();
		states.texture = m_texture;
		target.draw(m_vertices, 4, sf::Quads, states);
	}
}
