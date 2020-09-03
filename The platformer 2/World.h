#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <tinyxml2.h>

class World : sf::NonCopyable
{
public:
	explicit World(sf::RenderWindow& window);
public:
	void Update(float dt);
	void Render();
private:
	//tinyxml!!!
	void BuildWorld();
private:
	sf::RenderWindow& m_window;
};

