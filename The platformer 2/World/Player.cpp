#include "Player.h"
#include "TileMap.h"
#include <iostream>

Player::Player(sf::Texture& texture)
	:m_sprite(sf::seconds(5.0f)), m_velocity(0.f, -15.f), m_acceleration(0, 9.81f)
{
	m_running.SetSpriteSheet(texture);
	for (int i = 0; i < 5; ++i)
	{
		m_running.AddFrame({(i * 46) + (3 * 46), 50 * 3, 46, 50 });
	}
	m_sprite.SetAnimation(m_running);
	m_sprite.setPosition({ 350.f, 50.f });
}

void Player::HandleInput()
{
	sf::Vector2f velocity{ 0.f, 0.f };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += 1.f;
		m_sprite.setScale(sf::Vector2f(1.f, 1.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= 1.f;
		m_sprite.setScale(sf::Vector2f(-1.f, 1.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_isOnGround)
	{
		velocity.y -= 250.f;
		m_isOnGround = false;
	}

	if (!m_isOnGround)
	{
		velocity.y += 1.f;
		//m_sprite.move(sf::Vector2f(0, 1.f));
	}

	if (velocity == sf::Vector2f(0.f, 0.f))
	{
		m_sprite.Stop();
	}
	else
	{
		m_sprite.Play();
	}

	m_sprite.move(velocity);
}

void Player::Update(float dt, TileMap& map)
{
	HandleInput();

	if (map.CheckCollisionWithMap(GetPlayerRect()))
	{
		m_isOnGround = true;
	}
	else
	{
		m_isOnGround = false;
		m_sprite.move(sf::Vector2f(0, 1.f));
	}

	m_sprite.Update(sf::seconds(dt));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite);
}

