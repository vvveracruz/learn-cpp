sf::RectangleShape getRectangle( int length, int width ) {

  sf::RectangleShape rectangle( sf::Vector2f(length, width) );

  rectangle.setFillColor( sf::Color::Red );
  rectangle.setPosition( 320, 240 );

  rectangle.setOrigin( rectangle.getSize().x / 2, rectangle.getSize().y / 2 );

  return rectangle;
}
