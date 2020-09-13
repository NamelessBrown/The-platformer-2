
#include <SFML/Graphics.hpp>

class Goal : public sf::Drawable
{
public:
	Goal(sf::Texture& texture);
	~Goal() = default;
public:
	void SetPosition(const sf::Vector2f& position);
	void SetPosition(float x, float y);
	sf::IntRect GetGoalRect() const { return static_cast<sf::IntRect>(m_sprite.getGlobalBounds()); }
	const sf::Sprite& GetSprite() const { return m_sprite; }
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Sprite m_sprite;
};