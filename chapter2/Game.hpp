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

};
