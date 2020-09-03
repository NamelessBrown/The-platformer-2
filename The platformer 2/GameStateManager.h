#pragma once

#include <stack>
#include <memory>
#include "State.h"


class GameStateManager
{
public:
	GameStateManager() = default;
	GameStateManager(const GameStateManager&) = delete;
	GameStateManager& operator=(const GameStateManager&) = delete;
	~GameStateManager() = default;
public:
	void PushState(std::unique_ptr<State> state);
	void PopState();
	void ChangeState(std::unique_ptr<State> state);
	State* GetCurrentState() const
	{
		if (m_states.empty())
		{
			return nullptr;
		}

		return m_states.top().get();
	}
private:
	std::stack<std::unique_ptr<State>> m_states;

};

