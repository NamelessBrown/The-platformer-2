#include "State.h"

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures)
	:window(&window), textureHolder(&textures)
{
}

State::State(Context& context)
	:m_context(context)
{
}
