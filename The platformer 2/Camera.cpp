#include "Camera.h"

Camera::Camera(const sf::Vector2f& position)
{
	m_currentView.setCenter(position);
}

Camera::~Camera()
{
}

void Camera::MoveTo(const sf::Vector2f& position)
{
	m_currentView.move(position);
}

void Camera::Update(const sf::Vector2f& position)
{
	m_currentView.setCenter(position);
}
