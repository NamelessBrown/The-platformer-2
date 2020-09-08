#include "TitlescreenState.h"

TitlescreenState::TitlescreenState(Context& context)
	:State(context), m_world(context)
{
}

void TitlescreenState::HandleEvents(const sf::Event& events)
{

}

void TitlescreenState::Update(float dt)
{
	m_world.Update(dt);
}

void TitlescreenState::Draw()
{
	auto& window = *GetContext().window;
	window.draw(m_world);
}

void TitlescreenState::HandleCollision()
{

}
