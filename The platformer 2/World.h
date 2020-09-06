#pragma once

#include <SFML/Graphics.hpp>
#include <tinyxml2.h>
#include <string>

class World : sf::NonCopyable
{
public:
	explicit World(sf::RenderWindow& window);
public:
	void Update(float dt);
	void Render();
private:
	//tinyxml!!!
	void BuildWorld(const std::string& filename);
private:
	sf::RenderWindow& m_window;
};

