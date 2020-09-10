#include "World.h"
#include "ParsingException.h"
#include <iostream>

World::World(State::Context& context)
	:m_window(*context.window), m_tilemap(context.textureHolder->GetResource("tiles")), 
	m_player(context.textureHolder->GetResource("player"))
{
	BuildWorld("test.tmx");
}

void World::HandleEvents()
{
	m_player.HandleInput();
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
