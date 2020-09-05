#pragma once

#include <entt/entt.hpp>
#include "State.h"

class Entity
{
public:
	Entity(State::Context& context);
	Entity(entt::entity entity, State::Context& context);
	~Entity() = default;
public:
	template<typename T>
	bool HasComponent()
	{
		return m_context.registry->has<T>(m_entity);
	}
	template<typename T, typename... Args>
	T& AddComponent(Args&&... args)
	{
		assert(!HasComponent<T>() && "Already have the component");
		return m_context.registry->emplace<T>(m_entity, std::forward<Args>(args)...);
	}
	template<typename T>
	T& GetComponent()
	{
		assert(HasComponent<T>() && "Don't have the component");
		return m_context.registry->get<T>(m_entity);
	}
private:
	entt::entity m_entity;
	State::Context& m_context;
};

