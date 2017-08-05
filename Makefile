CC=g++
Sources=main.cpp Clases/Entitys/Entity.cpp Clases/Entitys/Enemy.cpp
CXXFLAGS= -Wall -ISFML-2.4.2/include/ -LSFML-2.4.2/lib/ -lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CC) $(Sources) -o main $(CXXFLAGS)
