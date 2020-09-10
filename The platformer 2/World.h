#pragma once

#include <SFML/Graphics.hpp>
#include <tinyxml2.h>
#include <string>
#include "TileMap.h"
#include "State.h"
#include "Player.h"

class World : sf::NonCopyable, public sf::Drawable
{
public:
	explicit World(State::Context& context);
public:
	void HandleEvents();
	void Update(float dt);
private:
	//tinyxml!!!
	void BuildWorld(const std::string& filename);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::RenderWindow& m_window;
	TileMap m_tilemap;
	Player m_player;
};

