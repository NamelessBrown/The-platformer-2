#include "World.h"
#include "ParsingException.h"

World::World(State::Context& context)
	:m_window(*context.window), m_tilemap(context.textureHolder->GetResource("tiles"))
{
	BuildWorld("test.tmx");
}

void World::Update(float dt)
{
}

void World::Render()
{
	m_window.draw(m_tilemap);
}

//tinyxml!!!
void World::BuildWorld(const std::string& filename)
{
	m_tilemap.Load(filename);
}
