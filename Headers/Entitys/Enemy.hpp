#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"

class Enemy : public Entity{

public:
  Enemy();
  Enemy(int dam, int heal, int velo, float pX, float pY);
  ~Enemy();

  void render();

  void setTexture(std::string textureFile);
  void setSprite();

  sf::Texture mTexture;
  sf::Sprite mSprite;

private:

  float posX;
  float posY;

  int health;
  int damage;
  int vel;

};

#endif
