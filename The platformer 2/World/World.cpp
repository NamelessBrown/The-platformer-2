#include "World.h"
#include "../Engine/ParsingException.h"
#include <iostream>

World::World(State::Context& context)
	:m_window(*context.window), m_tilemap(context.textureHolder->GetResource("tiles")), 
	m_player(context.textureHolder->GetResource("player"))
{
	BuildWorld("Levels/test.tmx");
}

void World::HandleEvents()
{
	sf::View view = m_window.getDefaultView();
	view.setCenter(m_player.GetPosition());
	m_window.setView(view);
}

void World::Update(float dt)
{
	m_player.Update(dt, m_tilemap);
}

//tinyxml!!!
void World::BuildWorld(const std::string& filename)
{
	m_tilemap.Load(filename);
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_tilemap);
	target.draw(m_player);
}
