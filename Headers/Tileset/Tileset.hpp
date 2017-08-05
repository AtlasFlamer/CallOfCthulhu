#ifndef TILESET_HPP
#define TILESET_HPP

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

class Tilemap : public sf::Drawable, public sf::Transformable{
public:
  bool load(const std::string& tilset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  sf::VertexArray m_vertices;
  sf::Texture m_tilset;
};


#endif
