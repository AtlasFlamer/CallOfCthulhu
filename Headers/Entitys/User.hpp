#ifndef USER_HPP
#define USER_HPP

#include "Entity.hpp"

class User : public Entity{

public:
  User();
  ~User();

  void update();
  void render();
  void setTexture(std::string textureFile);
  void setSprite();

  void uMove();

  float posX;
  float posY;

  sf::Texture mTexture;
  sf::Texture mTexture2;
  sf::Sprite mSprite;
};

#endif
