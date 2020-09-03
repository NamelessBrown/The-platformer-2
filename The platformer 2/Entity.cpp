#include "Entity.h"

Entity::Entity(State::Context& context)
	:m_context(context)
{
	m_entity = m_context.registry->create();
}

Entity::Entity(entt::entity entity, State::Context& context)
	:m_entity(entity), m_context(context)
{
}
