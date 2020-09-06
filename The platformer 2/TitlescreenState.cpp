#include "TitlescreenState.h"

TitlescreenState::TitlescreenState(Context& context)
	:State(context), m_world(*context.window), m_tilemap(context.textureHolder->GetResource("tiles"))
{
	m_tilemap.Load("test.tmx");
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

	window.draw(m_tilemap);
}

void TitlescreenState::HandleCollision()
{

}
