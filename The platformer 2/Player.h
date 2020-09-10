#pragma once

#include "AnimatedSprite.h"

class TileMap;
class Player : public sf::Drawable
{
public:
	Player(sf::Texture& texture);
public:
	sf::IntRect GetPlayerRect() const { return static_cast<sf::IntRect>(m_sprite.GetGlobalBounds()); }
	void HandleInput();
	void Update(float dt, TileMap& map);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	AnimatedSprite m_sprite;
	Animation m_running;
};

