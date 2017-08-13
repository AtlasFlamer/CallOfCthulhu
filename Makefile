CC=g++
Sources=main.cpp Clases/Entitys/Entity.cpp Clases/Entitys/Enemy.cpp Clases/Entitys/User.cpp Clases/Tileset/Tileset.cpp Clases/System/Collision.cpp
CXXFLAGS= -Wall -ISFML-2.4.2/include/ -LSFML-2.4.2/lib/ -lsfml-graphics-d -lsfml-window-d -lsfml-system-d

all:
	$(CC) $(Sources) -o main $(CXXFLAGS)
