#pragma once

#include "AnimatedSprite.h"

class TileMap;
class Player : public sf::Drawable
{
public:
	Player(sf::Texture& texture);
public:
	sf::IntRect GetPlayerRect() const { return static_cast<sf::IntRect>(m_sprite.GetGlobalBounds()); }
	sf::Vector2f GetPosition() const { return m_sprite.getPosition(); }
	void HandleInput();
	void Update(float dt, TileMap& map);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	AnimatedSprite m_sprite;
	Animation m_running;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
	bool m_isOnGround = false;
};

