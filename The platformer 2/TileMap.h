#pragma once

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    explicit TileMap(sf::Texture& texture);
    ~TileMap() = default;
public:
    bool Load(sf::Vector2u tileSize, const int* tiles, unsigned width, unsigned height);
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    sf::VertexArray m_vertices;
    sf::Texture& m_texture;
};

