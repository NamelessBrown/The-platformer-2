#include "TitlescreenState.h"
#include <iostream>

TitlescreenState::TitlescreenState(Context& context)
	:State(context), m_world(context), 
	m_button(sf::IntRect(0, 0, 405, 214), context.textureHolder->GetResource("boobs"))
{
	GUI::Button::Callback callback;
	callback = []() {std::cout << "hit!" << '\n'; };
	m_button.SetCallback(callback);
	m_button.setPosition(250.f, 250.f);
	m_button.setRotation(45.f);
}

void TitlescreenState::HandleEvents(const sf::Event& events)
{
	m_world.HandleEvents();
}

void TitlescreenState::Update(float dt)
{
	m_button.IsClicked(sf::Mouse::getPosition(*GetContext().window));
	m_world.Update(dt);
}

void TitlescreenState::Draw()
{
	auto& window = *GetContext().window;
	window.draw(m_button);
	window.draw(m_world);
}

void TitlescreenState::HandleCollision()
{

}
