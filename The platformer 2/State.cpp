#include "State.h"

State::Context::Context(sf::RenderWindow& window, entt::registry& registry, TextureHolder& textures)
	:window(&window), registry(&registry), textureHolder(&textures)
{
}

State::State(Context& context)
	:m_context(context)
{
}
