#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../World/World.h"
#include "../States/GameStateManager.h"
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
	TextureHolder m_textureHolder;
	GameStateManager m_stateManager;
};

