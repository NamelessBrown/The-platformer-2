#include "GameoverState.h"
#include "TitlescreenState.h"
#include "GameStateManager.h"

GameoverState::GameoverState(Context& context)
	:State(context), m_play(sf::IntRect(0, 0, 910, 359), context.textureHolder->GetResource("start")),
	m_quit(sf::IntRect(0, 0, 322, 156), context.textureHolder->GetResource("quit"))
{
	m_play.setScale(m_play.getScale() / 6.f);
	m_play.setPosition(250.f, 250.f);
	m_play.SetCallback([this, context]() mutable {
		auto titlescreen = std::make_unique<TitlescreenState>(context);
		context.gameStateManager->PushState(std::move(titlescreen));
		});

	m_quit.setScale(m_quit.getScale() / 2.f);
	m_quit.setPosition(250.f, 325.f);
	m_quit.SetCallback([this]() {GetContext().window->close(); });
}

void GameoverState::HandleEvents(const sf::Event& events)
{
	m_play.IsClicked(sf::Mouse::getPosition(*GetContext().window));
	m_quit.IsClicked(sf::Mouse::getPosition(*GetContext().window));
}

void GameoverState::Update(float dt)
{
}

void GameoverState::Draw()
{
	auto& window = *GetContext().window;
	window.draw(m_play);
	window.draw(m_quit);
}
