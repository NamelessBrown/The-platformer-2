#include "State.h"

State::Context::Context(sf::RenderWindow& window, entt::registry& registry)
	:window(&window), registry(&registry)
{
}

State::State(Context& context)
	:m_context(context)
{
}
