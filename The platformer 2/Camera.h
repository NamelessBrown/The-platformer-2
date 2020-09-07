#pragma once

#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera(const sf::Vector2f& position);
	~Camera();

	const sf::View& CurrentView() const { return m_currentView; }

	void MoveTo(const sf::Vector2f& position);
	void Update(const sf::Vector2f& position);

private:
	sf::View m_currentView;
};

