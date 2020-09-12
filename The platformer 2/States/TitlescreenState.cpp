#include "TitlescreenState.h"
#include <iostream>

TitlescreenState::TitlescreenState(Context& context)
	:State(context), m_play(sf::IntRect(0, 0, 910, 359), context.textureHolder->GetResource("start")),
	m_quit(sf::IntRect(0, 0, 322, 156), context.textureHolder->GetResource("quit"))
{
	m_play.setScale(m_play.getScale() / 6.f);
	sf::Vector2u windowSize = GetContext().window->getSize();
	m_play.setPosition(float(windowSize.x) / 2.f, float(windowSize.y) / 2.f);
	m_play.SetCallback([]() {std::cout << "Switch to play state" << '\n'; });

}

void TitlescreenState::HandleEvents(const sf::Event& events)
{
	m_play.IsClicked(sf::Mouse::getPosition(*GetContext().window));
}

void TitlescreenState::Update(float dt)
{
}

void TitlescreenState::Draw()
{
	auto& window = *GetContext().window;
	window.draw(m_play);
}