#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "World.h"
#include "GameStateManager.h"
#include "Resources.h"

class Engine
{
public:
	Engine();
public:
	void Running();
private:
	void HandleEvents();
	void Update(float dt);
	void LoadAllTextures(const std::string& filename);
	void Render();
private:
	sf::RenderWindow m_window;
	sf::Clock m_clock;
	entt::registry m_registry;
	TextureHolder m_textureHolder;
	GameStateManager m_stateManager;
};

