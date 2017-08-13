#include <SFML/Graphics.hpp>

#include "Headers/Entitys/Enemy.hpp"
#include "Headers/Tileset/Tileset.hpp"
#include "Headers/Entitys/User.hpp"
#include "Headers/System/Collision.hpp"

#include <SFML/System.hpp>

User user;
Enemy tEnemy(100, 100, 200, 128, 128);

sf::Font beba;

sf::Text GameOver;
sf::Text dialogs;

bool canDrawDialog = false;

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
  window.setFramerateLimit(60);

  Collision cColision;

  bool death = false;

  GameOver.setFont(beba);
  GameOver.setString("Game Over");
  GameOver.setCharacterSize(24);
  GameOver.setFillColor(sf::Color::White);
  GameOver.setStyle(sf::Text::Bold);

  dialogs.setFont(beba);
  dialogs.setCharacterSize(12);
  dialogs.setFillColor(sf::Color::White);
  dialogs.setStyle(sf::Text::Bold);

  const int level[] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  };


  Tilemap map;


  if(!map.load("assets/maptiles.png", sf::Vector2u(32,32), level, 25, 19)){
    return -1;
  }

  if(!beba.loadFromFile("assets/fonts/BebasNeue.ttf")){
    std::cout << "Couldnt load font" << std::endl;
  }

  user.setTexture("assets/right.png");
  user.setSprite();

  tEnemy.setTexture("assets/right.png");
  tEnemy.setSprite();

  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed){
        window.close();
      }
    }

    user.uMove();

    bool shouldMove = cColision.comprobarColision(user.posX, user.posY, level);

    if(cColision.heal == 0){
      user.health = cColision.heal;
    }

    std::cout << "Heal: " << cColision.heal << std::endl;

    if(shouldMove){
      if(user.isMovingDown){
        user.posY -= 2;
        std::cout << "Changed position" << std::endl;
      } else if(user.isMovingUp){
        user.posY += 2;
        std::cout << "Changed position" << std::endl;
      } else if(user.isMovingLeft){
        user.posX += 2;
        std::cout << "Changed position" << std::endl;
      } else if(user.isMovingRight){
        user.posX -= 2;
        std::cout << "Changed position" << std::endl;
      }

      user.isMovingLeft = false;
      user.isMovingRight = false;
      user.isMovingUp = false;
      user.isMovingDown = false;
    }

    if(user.update()){
      death = true;
      while(death){
        window.clear(sf::Color::Black);
        GameOver.setPosition(350, 250);
        window.draw(GameOver);
        window.display();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
          death = false;
          user.posX = 2 * 32;
          user.posY = 2 * 32;
          user.health = 200;
          cColision.heal = 200;
        }

      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && canDrawDialog){
      canDrawDialog = false;
    }

    if(((user.posX <= tEnemy.posX - 32 && user.posX >= tEnemy.posX) || user.posX == tEnemy.posX + 32) && (user.posY == tEnemy.posY)){
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
        dialogs.setPosition(tEnemy.posX + 32, tEnemy.posY - 32);
        dialogs.setString("Hola te matare");
        canDrawDialog = true;
      }
    }

    window.clear(sf::Color::Black);

    window.draw(map);
    window.draw(user.mSprite);
    window.draw(tEnemy.mSprite);

    if(canDrawDialog){
      window.draw(dialogs);
    }

    window.display();

  }

  return 0;
}
