/**************************************************************************
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 * 
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * For more information, please refer to <https://unlicense.org>
 **************************************************************************/
/**
 * @file game_engine.hpp
 * @details The part of Snake Game project, is created as a support sample
 *          for the `C++ Development` course for Game Design specialization.
 * @brief Game engine class definition. This class is used to manage the game.
 * @author Mihail Croitor <mcroitor@gmail.com>
 * @date 2024
 */
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
