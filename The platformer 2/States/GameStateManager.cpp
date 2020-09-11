#include "GameStateManager.h"

void GameStateManager::PushState(std::unique_ptr<State> state)
{
	m_states.push(std::move(state));
}

void GameStateManager::PopState()
{
	m_states.pop();
}

void GameStateManager::ChangeState(std::unique_ptr<State> state)
{
	if (!m_states.empty())
	{
		PopState();
	}

	PushState(std::move(state));
}
