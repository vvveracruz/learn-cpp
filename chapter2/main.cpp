#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"
#include "Window.hpp"

int main( int argc, char const *argv[] ) {

  Game game;

  while ( !game.GetWindow() -> IsDone() ) {

    game.HandleInput();
    game.Update();
    game.Render();

    // sf::sleep( sf::seconds( 0.2 ) );

    game.RestartClock();

  }

  return 0;
}
