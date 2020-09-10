#include "Player.h"
#include "TileMap.h"
#include <iostream>

Player::Player(sf::Texture& texture)
	:m_sprite(sf::seconds(5.0f))
{
	m_running.SetSpriteSheet(texture);
	for (int i = 0; i < 5; ++i)
	{
		m_running.AddFrame({(i * 46) + (3 * 46), 50 * 3, 46, 50 });
	}
	m_sprite.SetAnimation(m_running);
}

void Player::HandleInput()
{

}

void Player::Update(float dt, TileMap& map)
{
	if (map.CheckCollisionWithMap(GetPlayerRect()))
	{
		std::cout << "true" << '\n';
	}

	m_sprite.Update(sf::seconds(dt));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite);
}

