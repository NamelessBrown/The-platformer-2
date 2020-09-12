#include "PlayState.h"

PlayState::PlayState(State::Context& context)
	:State(context), m_world(context)
{
}

void PlayState::HandleEvents(const sf::Event& events)
{
	m_world.HandleEvents();
}

void PlayState::Update(float dt)
{
	m_world.Update(dt);
}

void PlayState::Draw()
{
	auto& window = *GetContext().window;
	window.draw(m_world);
}
