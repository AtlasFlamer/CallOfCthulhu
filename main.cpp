#include <SFML/Graphics.hpp>

#include "Headers/Entitys/Enemy.hpp"
#include "Headers/Tileset/Tileset.hpp"
#include "Headers/Entitys/User.hpp"
#include "Headers/System/Collision.hpp"

#include <SFML/System.hpp>

User user;
sf::Font beba;
sf::Text GameOver;

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

    window.clear(sf::Color::Black);

    window.draw(map);
    window.draw(user.mSprite);
    window.display();

  }

  return 0;
}
