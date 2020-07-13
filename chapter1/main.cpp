#include <SFML/Graphics.hpp>
#include <iostream>

#define FRUIT_FILEPATH "assets/fruit.png"

int main(int argc, char const *argv[]) {

  sf::RenderWindow window(sf::VideoMode(640,480), "First window!");

  sf::Texture fruitTex;
  if ( !fruitTex.loadFromFile( FRUIT_FILEPATH ) ) {

    std::cout << "Error loading file for texture" << std::endl;

  }

  sf::Sprite fruit;
  fruit.setTexture(fruitTex);
  sf::Vector2u fruitSize = fruitTex.getSize();
  fruit.setOrigin( fruitSize.x / 2, fruitSize.y / 2 );
  sf::Vector2f increment ( 0.4f, 0.4f );

  while ( window.isOpen() ) {

    sf::Event event;

    while ( window.pollEvent( event ) ) {

      if ( event.type == sf::Event::Closed ) {

        window.close();

      }
    }

    //continue here on page 13

    window.clear( sf::Color::Black ) ;

    window.draw( fruit );

    window.display();

  }

  return 0;
}
