#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

namespace GUI
{
	class Button : public sf::Drawable, public sf::Transformable
	{
	public:
		using Callback = std::function<void()>;
	public:
		Button(const sf::IntRect& buttonRect, const sf::Texture& texture);
		~Button() = default;
	public:
		void IsClicked(const sf::Sprite& sprite);
		void IsClicked(const sf::Vector2i& mousePosition);
		void SetColor(const sf::Color& color);
		void SetCallback(Callback callback);
		sf::FloatRect GetLocalBounds() const;
		sf::FloatRect GetGlobalBounds() const;
	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	private:
		sf::Vertex m_vertices[4];
		sf::Texture m_texture;
		sf::IntRect m_buttonRect;
		Callback m_callback;
	};
}

