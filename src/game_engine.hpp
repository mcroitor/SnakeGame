#pragma once
#include "apple.hpp"
#include "snake.hpp"
#include "board.hpp"

class GameEngine {
   Apple _apple;
   Snake _snake;
   Board _board;

   bool GameOver() const;
   char GetEvent() const;
   void UpdateScreen() const;
   void StatusBar() const;
public:
   GameEngine();
   void Init();
   void Run();

};
