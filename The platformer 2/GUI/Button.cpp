#include "Button.h"

namespace GUI
{
	Button::Button(const sf::IntRect& buttonRect, const sf::Texture& texture)
		:m_buttonRect(buttonRect), m_texture(texture)
	{
		m_vertices[0].position = sf::Vector2f(0.f, 0.f);
		m_vertices[1].position = sf::Vector2f(0.f, float(buttonRect.height));
		m_vertices[2].position = sf::Vector2f(float(buttonRect.width), float(buttonRect.height));
		m_vertices[3].position = sf::Vector2f(float(buttonRect.width), 0.f);

		float left = float(buttonRect.left) + 0.0001f;
		float right = left + float(buttonRect.width);
		float top = float(buttonRect.top);
		float bottom = top + float(buttonRect.height);

		m_vertices[0].texCoords = sf::Vector2f(left, top);
		m_vertices[1].texCoords = sf::Vector2f(left, bottom);
		m_vertices[2].texCoords = sf::Vector2f(right, bottom);
		m_vertices[3].texCoords = sf::Vector2f(right, top);
	}

	void Button::IsClicked(const sf::Sprite& sprite)
	{
		const sf::Mouse mouse;

		if (GetGlobalBounds().contains(sprite.getPosition()) && mouse.isButtonPressed(sf::Mouse::Left) && m_callback)
		{
			m_callback();
		}
	}

	void Button::IsClicked(const sf::Vector2i& mousePosition)
	{
		const sf::Mouse mouse;

		if (GetGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)) && mouse.isButtonPressed(sf::Mouse::Left) && m_callback)
		{
			m_callback();
		}
	}

	void Button::SetColor(const sf::Color& color)
	{
		m_vertices[0].color = color;
		m_vertices[1].color = color;
		m_vertices[2].color = color;
		m_vertices[3].color = color;
	}

	void Button::SetCallback(Callback callback)
	{
		m_callback = callback;
	}

	sf::FloatRect Button::GetLocalBounds() const
	{
		float width = (float)std::abs(m_buttonRect.width);
		float height = (float)std::abs(m_buttonRect.height);

		return sf::FloatRect(0.f, 0.f, width, height);
	}

	sf::FloatRect Button::GetGlobalBounds() const
	{
		return getTransform().transformRect(GetLocalBounds());
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = &m_texture;
		target.draw(m_vertices, 4, sf::Quads, states);
	}
}
