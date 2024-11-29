#pragma once
#include "apple.hpp"
#include "snake.hpp"
#include "board.hpp"
#include "abstract_painter.hpp"

class GameEngine {
   Apple _apple;
   Snake _snake;
   Board _board;
   int _score;
   int _speed;
   static const int MAX_TIME_MS = 100000;
   static const int DELTA_MS = 100;

public:
   /// @brief Default constructor.
   GameEngine();
   
   /// @brief Initializes the game.
   void Init();
   
   /// @brief Main game loop.
   void Run();
private:
   /// @brief Checks if the snake knocks the wall.
   /// @return true if the snake knocks the wall, false otherwise.
   bool SnakeKnocksWall() const;

   /// @brief Check if the game is over.
   /// @return true if the game is over, false otherwise.
   bool GameOver() const;

   /// @brief Reads the event from the keyboard.
   /// @return key pressed.
   char GetEvent() const;

   /// @brief Updates the screen.
   void UpdateScreen() const;

   /// @brief Updates the status of the game.
   void UpdateStatus() const;

   /// @brief Draws the board.
   /// @param painter
   void DrawBoard(const AbstractPainter& painter) const;
};
