#include "TileMap.h"
#include "ParsingException.h"
#include <algorithm>
#include <sstream>

/*
    How to solve this->problem
    Tinyxml Get the tileSize, rows, colums from the element tag (of course)
    Get the level data whole in put it in a string
    filter out the junk - (commas, 

*/

bool TileMap::Load(sf::Vector2u tileSize, const int* tiles, unsigned width, unsigned height)
{
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);
    m_width = width;
    m_height = height;
    m_tileSize = tileSize.x;

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
    :m_texture(texture), m_width(0), m_height(0), m_tileSize(0)
{
}

bool TileMap::Load(const std::string& filename)
{
    tinyxml2::XMLDocument document;
    document.LoadFile(filename.c_str());
    if (document.Error())
    {
        throw ParsingException{ std::string{ "Failed to load -> " + filename }.c_str() };
    }

    tinyxml2::XMLElement* root = document.RootElement();
    int maxRows = root->IntAttribute("height");
    int maxCols = root->IntAttribute("width");
    int tileSize = root->IntAttribute("tilewidth");
    TileData tileData;
    
    for (auto e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        std::string val{ e->Value() };
        if (val == "tileset")
        {
            tileData.tileCount = e->IntAttribute("tilecount");
            tileData.column = e->IntAttribute("columns");
            tileData.row = tileData.tileCount / tileData.column;
            tileData.tileSize = e->IntAttribute("tilewidth");
            tinyxml2::XMLElement* image = e->FirstChildElement();
            tileData.source = image->Attribute("source");
        }
        else if (val == "layer")
        {
            tinyxml2::XMLElement* data = nullptr;
            for (auto iter = e->FirstChildElement(); iter != nullptr; iter = iter->NextSiblingElement())
            {
                std::string dataStr{ iter->Value() };
                if (dataStr == "data")
                {
                    data = iter;
                    break;
                }
            }

            std::string matrix;
            if (data != nullptr)
            {
                matrix = data->GetText();
            }
            std::istringstream iss(matrix);
            std::string id;

            m_dataMap = std::vector<int>(maxRows * maxCols);
            for (int row = 0; row < maxRows; row++)
            {
                for (int column = 0; column < maxCols; column++)
                {
                    std::getline(iss, id, ',');
                    std::stringstream converter(id);
                    converter >> m_dataMap[row * maxCols + column];

                    if (!iss.good())
                    {
                        break;
                    }

                }
            }

            Load({ 32, 32 }, m_dataMap.data(), maxCols, maxRows);

        }


    }

    return false;
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
