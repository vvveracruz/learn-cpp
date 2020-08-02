#include <SFML/Graphics.hpp>
#include <iostream>

struct SnakeSegment {

  SnakeSegment( int x, int y ): position( x, y ) {}
  sf::Vector2i position;

};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction { None, Up, Down, Left, Right };

class Snake {

public:
  Snake( int, l_blockSize );
  ~Snake( );

  // Helper methods
  void SetDirection( Direction l_dir );
  Direction GetDirection( );
  int GetSpeed( );
  sf::Vector2i GetPosition( );
  int GetLives( );
  int GetScore( );
  void IncreaseScore( );
  bool HasLost( );

  void Lose( );
  void ToggleLost( );

  void Extend( ); // Grow the Snake
  void Restet( ); // Reset to starting position

  void Move( );
  void Tick( );
  void Cut( int l_segments );
  void Render( sf::RenderWindow& l_window );

private:
  void CheckCollision( );

  SnakeContainer m_snakeBody; // segment vector
  int m_size; // size of graphics
  Direction m_dir; // current direction
  int m_speed;
  int m_lives;
  int m_score;
  bool m_lost;
  sf::RectangleShape m_bodyRect;

};
