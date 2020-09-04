#include "World.h"
#include "ParsingException.h"

World::World(sf::RenderWindow& window)
	:m_window(window)
{
	//BuildWorld("");
}

void World::Update(float dt)
{
}

void World::Render()
{

}

//tinyxml!!!
void World::BuildWorld(const std::string& filename)
{
	/* tinyxml2::XMLDocument document;
	document.LoadFile(filename.c_str());
	if (document.Error())
	{
		std::string error{ "Failed to load file " + filename };
		throw ParsingException{ error.c_str() };
	}

	tinyxml2::XMLElement* root = document.RootElement();
	for (auto element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement())
	{
		element->Attribute()
	}
	*/

}
