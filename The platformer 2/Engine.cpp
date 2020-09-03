#include "Engine.h"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "TitlescreenState.h"

Engine::Engine()
	:m_window(sf::VideoMode{1280, 720}, "The platformer 2", sf::Style::Close)
{
	State::Context context(m_window, m_registry);
	auto titleScreen = std::make_unique<TitlescreenState>(context);
	m_stateManager.PushState(std::move(titleScreen));
}

void Engine::Running()
{
	const sf::Time framerate = sf::seconds(1.f / 60.f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		HandleEvents();

		sf::Time elapsedTime = m_clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > framerate)
		{
			timeSinceLastUpdate -= framerate;
			Update(framerate.asSeconds());
		}

		Render();
	}
}

void Engine::HandleEvents()
{
	sf::Event events;
	while (m_window.pollEvent(events))
	{
		switch (events.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		}
	}

	m_stateManager.GetCurrentState()->HandleEvents(events);

}

void Engine::Update(float dt)
{
	m_stateManager.GetCurrentState()->Update(dt);
}

void Engine::Render()
{
	m_window.clear();
	m_stateManager.GetCurrentState()->Draw();
	m_window.display();
}
