#include "World.h"
#include "ParsingException.h"
#include <iostream>

World::World(State::Context& context)
	:m_window(*context.window), m_tilemap(context.textureHolder->GetResource("tiles")), m_camera({0.f, 0.f}),
	m_player(context.textureHolder->GetResource("player"))
{
	BuildWorld("test.tmx");
}

void World::Update(float dt)
{

	m_camera.Update(m_player.GetPosition());
	m_player.Update(dt);
}

void World::Render()
{
	//m_window.setView(m_camera.CurrentView());
	m_player.Render(m_window);
	m_window.draw(m_tilemap);
}

bool World::CheckCollisionWithMap(const sf::IntRect& rect)
{
	const int tileSize = m_tilemap.GetTileSize();
	const int tileRows = m_tilemap.GetHeight();
	const int tileColumns = m_tilemap.GetWidth();

	int left_tile = rect.left / tileSize;
	int right_tile = (rect.left + rect.width) / tileSize;
	int top_tile = rect.top / tileSize;
	int bottom_tile = (rect.top + rect.height) / tileSize;

	if (left_tile < 0)
	{
		left_tile = 0;
	}
	if (right_tile > tileColumns)
	{
		right_tile = tileColumns;
	}
	if (top_tile < 0)
	{
		top_tile = 0;
	}
	if (bottom_tile > tileRows)
	{
		bottom_tile = tileRows;
	}

	for (auto i = left_tile; i <= right_tile; ++i)
	{
		for (auto j = top_tile; j <= bottom_tile; ++j)
		{
			if (m_tilemap.GetTileAt(i, j) > 0)
			{
				return true;
			}
		}
	}

	return false;
}

//tinyxml!!!
void World::BuildWorld(const std::string& filename)
{
	m_tilemap.Load(filename);
}