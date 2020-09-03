#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "World.h"
#include "GameStateManager.h"

class Engine
{
public:
	Engine();
public:
	void Running();
private:
	void HandleEvents();
	void Update(float dt);
	void Render();
private:
	sf::RenderWindow m_window;
	sf::Clock m_clock;
	entt::registry m_registry;
	GameStateManager m_stateManager;
};

