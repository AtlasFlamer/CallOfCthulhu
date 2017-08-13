#include "../../Headers/System/Collision.hpp"
#include <iostream>

Collision::Collision(){

}

Collision::~Collision(){

}

bool Collision::comprobarColision(int posX, int posY, const int aLevel[]){


  std::cout << "Array position: " << aLevel[posX/(800/25)+(posY/(600/19))*25] << " Array Position Y " << aLevel[posY / 2] << std::endl;
std::cout << "user posX: " << posX << " user posY " << posY << std::endl;

  if(aLevel[(posX/(800/25)+(posY/(600/19))*25) + 1] == 1 || aLevel[(posX/(800/25)+(posY/(600/19))*25)] == 1){
    std::cout << "condicion cumplida" << std::endl;
    return true;
  } else if(aLevel[(posX/(800/25)+(posY/(600/19))*25) + 1] == 2){
    return true;
  }

  return false;
}
