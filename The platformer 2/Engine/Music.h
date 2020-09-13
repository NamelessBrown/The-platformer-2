#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <random>

class Music
{
public:
	Music();

	void Play();
	const sf::Music& getSong() const;
private:
	sf::Music m_music;
	std::vector<std::string> m_songs;

	std::random_device m_rd;
	std::mt19937 m_mt;

	int m_WhatFile;
};

