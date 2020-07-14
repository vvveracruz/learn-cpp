#pragma once

#include "Window.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Game {

public:
  Game();
  ~Game();

  void HandleInput();
  void Update();
  void Render();
  
  Window* GetWindow();

private:
  void MoveFruit();

  Window m_window;

  sf::Texture m_fruitTexture;
  sf::Sprite m_fruit;
  sf::Vector2i m_increment;

};
