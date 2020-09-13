#include "Engine.h"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "../States/TitlescreenState.h"
#include "ParsingException.h"

Engine::Engine()
	:m_window(sf::VideoMode{1280, 720}, "The platformer 2", sf::Style::Close)
{
	LoadAllTextures("Textures.tml");
	State::Context context(m_window, m_textureHolder, m_stateManager);
	auto titleScreen = std::make_unique<TitlescreenState>(context);
	m_stateManager.PushState(std::move(titleScreen));
}

void Engine::Running()
{
	const sf::Time framerate = sf::seconds(1.f / 60.f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		float dt = m_clock.restart().asSeconds() * 60.f;
		HandleEvents();
		Update(dt);
		Render();

		if (m_music.getSong().getStatus() == sf::Music::Stopped)
		{
			m_music.Play();
		}

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

void Engine::LoadAllTextures(const std::string& filename)
{
	tinyxml2::XMLDocument document;
	document.LoadFile(filename.c_str());
	if (document.Error())
	{
		std::string error{ "Failed to load file " + filename };
		throw ParsingException{ error.c_str() };
	}

	tinyxml2::XMLElement* root = document.RootElement();
	for (auto element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement())
	{
		std::string value{ element->Value() };
		if (value == "texture")
		{
			std::string id = element->Attribute("id");
			std::string filename = element->Attribute("src");
			m_textureHolder.Load(id, filename);
		}
	}
}

void Engine::Render()
{
	m_window.clear();
	m_stateManager.GetCurrentState()->Draw();
	m_window.setView(m_window.getDefaultView());
	m_window.display();
}
