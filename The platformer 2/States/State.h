#pragma once

#include <SFML/Graphics.hpp>
#include "../Engine/Resources.h"

class GameStateManager;
class State
{
public:
	struct Context
	{
		Context(sf::RenderWindow& window, TextureHolder& textures, GameStateManager& stateManager);
		sf::RenderWindow* window;
		TextureHolder* textureHolder;
		GameStateManager* gameStateManager;
	};
public:
	State(Context& context);
	virtual ~State() = default;
public:
	virtual void HandleEvents(const sf::Event& events) = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
protected:
	Context GetContext() const
	{
		return m_context;
	}
private:
	Context m_context;
};

