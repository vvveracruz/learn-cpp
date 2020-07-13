#include <SFML/Graphics.hpp>
#include <iostream>

#define FRUIT_FILEPATH "../assets/fruit.png"

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

    if ( ( fruit.getPosition().x + ( fruitSize.x / 2 ) > window.getSize().x && increment.x > 0 ) || ( fruit.getPosition().x - ( fruitSize.x / 2 ) < 0 && increment.x < 0 ) ) {

      increment.x = - increment.x;
      //reversing the direction on x axis

    }

    if ( ( fruit.getPosition().y + ( fruitSize.y / 2 ) > window.getSize().y && increment.y > 0 ) || ( fruit.getPosition().y - ( fruitSize.y / 2 ) < 0 && increment.y < 0 ) ) {

      increment.y = - increment.y;
      //reversing the direction on y axis

    }

    fruit.setPosition( fruit.getPosition() + increment );

    window.clear( sf::Color::Black ) ;

    window.draw( fruit );

    window.display();

  }

  return 0;
}
