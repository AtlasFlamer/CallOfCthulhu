#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

class Entity{

public:

  Entity();
  Entity(int pX, int pY);
  ~Entity();

  virtual void render()             = 0;

  virtual void setTexture(std::string textureFile)         = 0;
  virtual sf::Texture getTexture()  = 0;

  virtual void setSprite()         = 0;
  virtual sf::Sprite getSprite()    = 0;

private:

  int posX;
  int posY;

  sf::Texture mTexture;
  sf::Sprite mSprite;

};

#endif
