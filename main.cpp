#include <SFML/Graphics.hpp>
#include "Headers/Entitys/Enemy.hpp"


int main() {

  Enemy cthulhu(80, 100, 5, 100.0f, 80.0f);

  sf::RenderWindow window(sf::VideoMode(800, 600), "Test");

  cthulhu.setTexture("test.png");
  cthulhu.setSprite();


  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed){
        window.close();
      }
    }

    window.clear(sf::Color::Black);
    window.draw(cthulhu.getSprite());
    window.display();

  }

  return 0;
}
