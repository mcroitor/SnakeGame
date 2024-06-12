#pragma once

#include "tuia.hpp"

#include "apple.hpp"
#include "snake.hpp"
#include "board.hpp"

using tuia = usm::graphics::TUIA;
using point = usm::graphics::Point;
using background_color = usm::graphics::BackgroundColor;
using foreground_color = usm::graphics::ForegroundColor;

class GameEngine {
   Apple _apple;
   Snake _snake;
   Board _board;
   size_t _score;
   size_t _speed;

   background_color _background_color;
   foreground_color _text_color;
   background_color _status_bar_color;
   foreground_color _apple_color;
   foreground_color _snake_color;

   bool GameOver() const;
   char GetEvent() const;
   void UpdateScreen() const;
   void UpdateStatus() const;
   void DrawApple() const;
   void DrawSnake() const;
public:
   GameEngine();
   void Init();
   void Run();

   ~GameEngine();
};
