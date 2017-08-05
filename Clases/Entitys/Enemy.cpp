#include "../../Headers/Entitys/Enemy.hpp"

Enemy::Enemy(){

}

Enemy::Enemy(int dam, int heal, int velo, float pX, float pY){
  health = heal;
  damage = dam;
  vel = vel;

  posX = pX;
  posY = pY;
}

Enemy::~Enemy(){

}

void Enemy::render(){

}

void Enemy::setTexture(std::string textureFile){

  if(!mTexture.loadFromFile(textureFile, sf::IntRect(32,32,32,32))){
    std::cout << "Error al cargar: " << textureFile << std::endl;
  }

  mTexture.setSmooth(true);
}


void Enemy::setSprite(){
  mSprite.setTexture(mTexture);
  mSprite.setPosition(posX, posY);
}
