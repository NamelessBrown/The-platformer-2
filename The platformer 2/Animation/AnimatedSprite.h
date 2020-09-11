#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"

class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
public:
	AnimatedSprite(sf::Time frameTime = sf::seconds(0.2f), bool paused = false, bool loop = true);
public:
    void Update(sf::Time deltaTime);
    void SetAnimation(const Animation& animation);
    void SetFrameTime(sf::Time time);
    void Play();
    void Play(const Animation& animation);
    void Pause();
    void Stop();
    void SetLooped(bool looped);
    void SetColor(const sf::Color& color);
    const Animation* GetAnimation() const;
    sf::FloatRect GetLocalBounds() const;
    sf::FloatRect GetGlobalBounds() const;
    bool IsLooped() const;
    bool IsPlaying() const;
    sf::Time GetFrameTime() const;
    void SetFrame(std::size_t newFrame, bool resetTime = true);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	const Animation* m_animation = nullptr;
	sf::Time m_frameTime;
	sf::Time m_currentTime;
	size_t m_currentFrame;
	bool m_isPaused;
	bool m_isLooped;
	const sf::Texture* m_texture = nullptr;
	sf::Vertex m_vertices[4];

};

