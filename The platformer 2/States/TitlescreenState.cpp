#include "TitlescreenState.h"
#include "PlayState.h"
#include "GameStateManager.h"

TitlescreenState::TitlescreenState(Context& context)
	:State(context), m_play(sf::IntRect(0, 0, 910, 359), context.textureHolder->GetResource("start")),
	m_quit(sf::IntRect(0, 0, 322, 156), context.textureHolder->GetResource("quit"))
{
	m_play.setScale(m_play.getScale() / 6.f);
	m_play.setPosition(0.f, 250.f);
	m_play.SetCallback([this, context]() mutable {
		auto playState = std::make_unique<PlayState>(context);
		GetContext().gameStateManager->PushState(std::move(playState));
		});

	m_quit.setScale(m_quit.getScale() / 2.f);
	m_quit.setPosition(0.f, 325.f);
	m_quit.SetCallback([this]() {GetContext().window->close(); });
	m_background.setTexture(context.textureHolder->GetResource("title"));
	m_background.setPosition(250.f, 150.f);
}

void TitlescreenState::HandleEvents(const sf::Event& events)
{
	m_play.IsClicked(sf::Mouse::getPosition(*GetContext().window));
	m_quit.IsClicked(sf::Mouse::getPosition(*GetContext().window));
}

void TitlescreenState::Update(float dt)
{
}

void TitlescreenState::Draw()
{
	auto& window = *GetContext().window;
	window.draw(m_background);
	window.draw(m_play);
	window.draw(m_quit);
}