#include <string>
#include <iostream>

namespace vgg {

  std::string centerString( std::string message, int messageWidth ) {

    std::string output;

    int sides = ( messageWidth - message.length() ) / 2;
    bool evenSides = false;

    if ( ( messageWidth - message.length() ) % 2 == 0 ) {
      evenSides = true;
    }

    for ( int i = 0; i < sides; i ++) {
      output += " ";
    }

    output += message;

    if ( evenSides == true ) {

      for ( int i = 0; i < sides; i ++) {
        output += " ";
      }

    } else {

      for ( int i = 0; i < sides + 1; i ++) {
        output += " ";

      }
    }

    return output;
  }

  std::string titleTop( char c, int messageWidth ) {

    std::string output;

    for ( int i = 0; i < messageWidth; i++ ){

      output += c;

    }

    return output;

  }
}
