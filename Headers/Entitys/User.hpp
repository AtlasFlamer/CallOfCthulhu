#ifndef USER_HPP
#define USER_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "../Tileset/Tileset.hpp"
#include <SFML/System.hpp>

class User : public Entity{

public:
  User();
  ~User();

  bool update();
  void render();
  void setTexture(std::string textureFile);
  void setSprite();

  void uMove();

  float posX;
  float posY;

  int health;

  bool isMovingLeft;
  bool isMovingRight;
  bool isMovingUp;
  bool isMovingDown;

  sf::Texture mTexture;
  sf::Texture mTexture2;

  sf::Sprite mSprite;
};

#endif
