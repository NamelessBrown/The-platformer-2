#include "World.h"
#include "../Engine/ParsingException.h"
#include <iostream>
#include <random>

World::World(State::Context& context)
	:m_window(*context.window), m_tilemap(context.textureHolder->GetResource("tiles2")),
	m_player(context.textureHolder->GetResource("player")),
	m_goal(context.textureHolder->GetResource("boobs")), m_currentLevel(1)
{
	m_background.setPosition(-350.f, 0.f);
	m_background.setTexture(context.textureHolder->GetResource("background"), true);
	BuildWorld();
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


	if (m_player.GetPosition().y > 30 * 32)
	{
		m_window.close();
	}
	sf::IntRect rect = m_goal.GetGoalRect();
	if (m_goal.GetGoalRect().intersects(m_player.GetPlayerRect()))
	{
		++m_currentLevel;
		BuildWorld();
	}

}

//tinyxml!!!
void World::BuildWorld()
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<float> distributionX(3000.f, 4000.f);
	std::uniform_real_distribution<float> distributionY(350.f, 600.f);

	m_goal.SetPosition(distributionX(rng), distributionY(rng));
	m_player.SetPosition(350.f, 50.f);
	switch (m_currentLevel)
	{
	case 1:
		m_tilemap.Load("Levels/level1.tmx");
		break;
	case 2:
		m_tilemap.Load("Levels/level2.tmx");
		break;
	case 3:
		m_tilemap.Load("Levels/level3.tmx");
		break;
	case 4:
		m_tilemap.Load("Levels/level4.tmx");
		break;
	case 5:
		m_tilemap.Load("Levels/level5.tmx");
		break;
	case 6:
		m_tilemap.Load("Levels/level6.tmx");
		break;
	case 7:
		m_tilemap.Load("Levels/level7.tmx");
		break;
	case 8:
		m_tilemap.Load("Levels/level8.tmx");
		break;
	case 9:
		m_tilemap.Load("Levels/level9.tmx");
		break;
	case 10:
		m_tilemap.Load("Levels/level10.tmx");
		break;
	default:
		m_currentLevel = 1;
		m_tilemap.Load("Levels/level1.tmx");
		break;
	}
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	target.draw(m_background);
	target.draw(m_tilemap);
	target.draw(m_player);
	target.draw(m_goal);
}
