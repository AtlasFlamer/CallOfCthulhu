#ifndef COLLISION_HPP
#define COLLISION_HPP

class Collision{
public:
  Collision();
  ~Collision();

  int heal;
  bool comprobarColision(int posX, int posY, const int aLevel[]);
};

#endif
