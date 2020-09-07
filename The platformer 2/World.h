#pragma once

#include <SFML/Graphics.hpp>
#include <tinyxml2.h>
#include <string>
#include "TileMap.h"
#include "State.h"
#include "Camera.h"
#include "Player.h"

class World : sf::NonCopyable
{
public:
	explicit World(State::Context& context);
public:
	void Update(float dt);
	void Render();
	bool CheckCollisionWithMap(const sf::IntRect& rect);
private:
	//tinyxml!!!
	void BuildWorld(const std::string& filename);
private:
	sf::RenderWindow& m_window;
	TileMap m_tilemap;
	Camera m_camera;
	Player m_player;
};

