#include "../../Headers/Entitys/User.hpp"


User::User(){
  health = 100;
}

User::~User(){

}

void User::render(){

}

void User::update(){
  if(health <= 0){
    exit(1);
  }
  mSprite.setPosition(posX, posY);
}

void User::setTexture(std::string textureFile){
  if(!mTexture.loadFromFile(textureFile, sf::IntRect(0,0,32,32))){
    exit(1);
  }

  if(!mTexture2.loadFromFile("assets/left.png", sf::IntRect(0,0,32,32))){
    exit(1);
  }

  mTexture.setSmooth(true);
}

void User::setSprite(){
  mSprite.setTexture(mTexture);
  mSprite.setPosition(500, 500);
}

void User::uMove(){

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    posX--;
    mSprite.setTexture(mTexture2);
    isMovingLeft = true;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    posX++;
    mSprite.setTexture(mTexture);
    isMovingRight = true;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    posY--;
    isMovingUp = true;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    posY++;
    isMovingDown = true;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
    posX -= 2;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
    posX += 2;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
    posY -= 2;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
    posY += 2;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){

      for(int i=0; i<53; i++){
        posX += 2;
        posY -= 2;
        update();
        sf::sleep(sf::milliseconds(10));
      }

      for(int i=0; i<53; i++){
        posX += 2;
        posY += 2;
        update();
        sf::sleep(sf::milliseconds(10));
      }
  }
}
