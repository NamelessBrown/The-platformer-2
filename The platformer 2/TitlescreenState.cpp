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
	

}

void TitlescreenState::Draw()
{
	auto& window = *GetContext().window;
	m_world.Render();
}

void TitlescreenState::HandleCollision()
{

}
