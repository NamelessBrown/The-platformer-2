#include "Music.h"

Music::Music()
	:m_rd(), m_mt(m_rd()), m_WhatFile(0)
{
	m_songs.emplace_back("Music/Wallpaper.ogg");
	m_songs.emplace_back("Music/Run Amok.ogg");
	m_songs.emplace_back("Music/The Builder.ogg");
	m_songs.emplace_back("Music/If I Had a Chicken - Kevin MacLeod.ogg");
	m_songs.emplace_back("Music/Life of Riley.ogg");
}

void Music::Play()
{
	std::uniform_int_distribution<int> distribution(0, m_songs.size() - 1);
	m_WhatFile = distribution(m_mt);

	m_music.openFromFile(m_songs.at(m_WhatFile));

	m_music.play();

}

const sf::Music& Music::getSong() const
{
	return m_music;
}
