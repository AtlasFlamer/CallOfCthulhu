#include "../../Headers/System/Collision.hpp"
#include <iostream>

Collision::Collision(){

}

Collision::~Collision(){

}

bool Collision::comprobarColision(int posX, int posY, const int aLevel[]){


  std::cout << "Array position: " << aLevel[posX / 2] << " Array Position Y " << aLevel[posY / 2] << std::endl;
std::cout << "user posX: " << posX << " user posY " << posY << std::endl;

  if(aLevel[posY / 2] == 1 && aLevel[posX / 2] == 1){
    std::cout << "condicion cumplida" << std::endl;
    return true;
  }

  return false;
}
