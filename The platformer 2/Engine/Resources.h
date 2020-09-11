#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <SFML/Graphics/Texture.hpp>

template<typename Resource>
class ResourceHolder
{
public:
	void Load(const std::string& item, const std::string& filename)
	{
		std::unique_ptr<Resource> resource = std::make_unique<Resource>();
		if (!resource->loadFromFile(filename))
		{
			throw std::runtime_error("Failed to load this->" + filename);
		}

		auto inserted = m_resources.insert(std::make_pair(item, std::move(resource)));
		assert(inserted.second);

	}
	template<typename SecondParameter>
	void Load(const std::string& item, const std::string& filename, const SecondParameter& secondParameter)
	{
		std::unique_ptr<Resource> resource = std::make_unique<Resource>();
		if (!resource->loadFromFile(filename, secondParameter))
		{
			throw std::runtime_error("Can't load this->" + filename);
		}


		auto inserted = m_resources.insert(std::make_pair(item, std::move(resource)));
		assert(inserted.second);
	}
	Resource& GetResource(const std::string& item)
	{
		auto found = m_resources.find(item);
		assert(found != m_resources.end());

		return *found->second;

	}
	const Resource& GetResource(const std::string& item) const
	{
		auto found = m_resources.find(item);
		assert(found != m_resources.end());

		return *found->second;
	}
private:
	std::unordered_map<std::string, std::unique_ptr<Resource>> m_resources;
};

using TextureHolder = ResourceHolder<sf::Texture>;