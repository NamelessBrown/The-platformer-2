#include "State.h"

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, GameStateManager& stateManager)
	:window(&window), textureHolder(&textures), gameStateManager(&stateManager)
{
}

State::State(Context& context)
	:m_context(context)
{
}
