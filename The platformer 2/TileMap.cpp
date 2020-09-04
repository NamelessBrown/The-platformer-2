#include "TileMap.h"

bool TileMap::Load(sf::Vector2u tileSize, const int* tiles, unsigned width, unsigned height)
{
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    for (unsigned i = 0; i < width; ++i)
    {
        for (unsigned j = 0; j < height; ++j)
        {
            int tileNumber = tiles[i + j * width];

            int tu = tileNumber % (m_texture.getSize().x / tileSize.x);
            int tv = tileNumber / (m_texture.getSize().x / tileSize.x);

            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            quad[0].position = sf::Vector2f(float(i * tileSize.x), float(j * tileSize.y));
            quad[1].position = sf::Vector2f((float)(i + 1) * tileSize.x, (float)j * tileSize.y);
            quad[2].position = sf::Vector2f((float)(i + 1) * tileSize.x, (float)(j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f((float)i * tileSize.x, (float)(j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f((float)tu * tileSize.x, (float)tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((float)(tu + 1) * tileSize.x, (float)tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((float)(tu + 1) * tileSize.x, (float)(tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f((float)tu * tileSize.x, (float)(tv + 1) * tileSize.y);

        }
    }



    return true;
}

TileMap::TileMap(sf::Texture& texture)
    :m_texture(texture)
{
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_texture;

    // draw the vertex array
    target.draw(m_vertices, states);
}
