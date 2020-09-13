#pragma once

#include <SFML/Graphics.hpp>
#include <tinyxml2.h>
#include <string>
#include "TileMap.h"
#include "../States/State.h"
#include "Player.h"
#include "Goal.h"

class World : sf::NonCopyable, public sf::Drawable
{
public:
	explicit World(State::Context& context);
public:
	void HandleEvents();
	void Update(float dt);
private:
	//tinyxml!!!
	void BuildWorld();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::RenderWindow& m_window;
	TileMap m_tilemap;
	int m_currentLevel;
	sf::Sprite m_background;
	Player m_player;
	Goal m_goal;
};

