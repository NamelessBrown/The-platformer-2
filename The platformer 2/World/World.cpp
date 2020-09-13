#include "World.h"
#include "../Engine/ParsingException.h"
#include <iostream>

World::World(State::Context& context)
	:m_window(*context.window), m_tilemap(context.textureHolder->GetResource("tiles")), 
	m_player(context.textureHolder->GetResource("player")), 
	m_goal(context.textureHolder->GetResource("boobs"))
{
	m_background.setPosition(-350.f, 0.f);
	m_background.setTexture(context.textureHolder->GetResource("background"), true);
	BuildWorld("Levels/test.tmx");
}

void World::HandleEvents()
{

}

void World::Update(float dt)
{
	m_player.Update(dt, m_tilemap);

	sf::View view = m_window.getDefaultView();
	view.setCenter(m_player.GetPosition().x, 500.f);
	m_window.setView(view);

	if (m_player.GetPosition().y > view.getSize().y)
	{
		m_window.close();
	}
	if (m_goal.GetGoalRect().intersects(m_player.GetPlayerRect()))
	{
		//load new level spawn new goal
	}

}

//tinyxml!!!
void World::BuildWorld(const std::string& filename)
{
	m_goal.SetPosition(1500.f, 350.f);
	m_tilemap.Load(filename);
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	target.draw(m_background);
	target.draw(m_tilemap);
	target.draw(m_player);
	target.draw(m_goal);
}
