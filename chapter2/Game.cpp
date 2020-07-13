#include "Game.hpp"
#include "DEFINITIONS.cpp"

/*----    CONSTRUCTOR & DESTRUCTOR    ----*/

Game::Game(): m_window( WINDOW_NAME, sf::Vector2u( WINDOW_WIDTH, WINDOW_HEIGHT ) ) {

  m_fruitTexture.loadFromFile( FRUIT_FILEPATH );
  m_fruit.setTexture( m_fruitTexture );
  m_increment = sf::Vector2i( SPEED_X, SPEED_Y );

}

Game::~Game() { }

/*----    HELPER METHODS    ----*/

void Game::Update() {

  m_window.Update();
  MoveFruit();

}

void Game::MoveFruit() {

  sf::Vector2u l_windowSize = m_window.GetWindowSize();
  sf::Vector2u l_textSize = m_fruitTexture.getSize();

  if ( ( m_fruit.getPosition().x > l_windowSize.x - l_textSize.x && m_increment.x > 0 ) || ( m_fruit.getPosition().x < 0 && m_increment.x < 0 ) ) {

    m_increment.x = -m_increment.x;

  }

  if ( ( m_fruit.getPosition().y > l_windowSize.y - l_textSize.y && m_increment.y > 0 ) || ( m_fruit.getPosition().y < 0 && m_increment.y < 0 ) ) {

    m_increment.y = -m_increment.y;

  }

  m_fruit.setPosition(
    m_fruit.getPosition().x + m_increment.x,
    m_fruit.getPosition().y + m_increment.y );

}

void Game::Render() {

  m_window.BeginDraw();
  m_window.Draw( m_fruit );
  m_window.EndDraw();

}
