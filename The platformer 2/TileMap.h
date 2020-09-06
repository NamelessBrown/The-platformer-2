#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <tinyxml2.h>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    explicit TileMap(sf::Texture& texture);
    ~TileMap() = default;
public:
    bool Load(const std::string& filename);
    int GetTileAt(int i, int j) const
    {
        return m_dataMap[i + j * m_width];
    }
    int GetWidth() const
    {
        return m_width;
    }
    int GetHeight() const
    {
        return m_height;
    }
    int GetTileSize() const
    {
        return m_tileSize;
    }
    const std::vector<int>& GetTileMap() const
    {
        return m_dataMap;
    }
private:
    struct TileData
    {
        int row = 0;
        int column = 0;
        int tileCount = 0;
        int tileSize = 0;
        std::string source;
    };
private:
    bool Load(sf::Vector2u tileSize, const int* tiles, unsigned width, unsigned height);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    sf::VertexArray m_vertices;
    sf::Texture& m_texture;
    int m_width;
    int m_height;
    int m_tileSize;
    std::vector<int> m_dataMap;
};

