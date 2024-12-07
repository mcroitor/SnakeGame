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
 * @file snake.hpp
 * @details The part of Snake Game project, is created as a support sample
 *          for the `C++ Development` course for Game Design specialization.
 * @brief This file contains the definition of the Snake class.
 * @author Mihail Croitor <mcroitor@gmail.com>
 * @date 2024
 */
#pragma once

#include <deque>

#include "apple.hpp"
#include "direction.hpp"
#include "point.hpp"

class Snake {
   static const int MAX_SIZE = 100;
   std::deque<Point> _segments;
   int _nr_segments;

public:
   /// @brief Default constructor. Creates a snake with 
   ///        one segment, at the position (1, 1).
   Snake();
   /// @brief Creates a snake with one segment, at the given position.
   /// @param _position 
   Snake(const Point& _position);
   /// @brief Move the snake in the given direction.
   /// @param direction 
   void Move(Direction direction);
   /// @brief Returns the number of segments of the snake.
   /// @return 
   int GetSize() const;
   /// @brief Returns the position of the snake.
   /// @return
   Point GetPosition() const;
   /// @brief Try to eat the apple. If the snake eats the apple,
   ///        the snake will grow with one segment.
   /// @param apple 
   void Eat(const Apple& apple);
   /// @brief Check if the snake eats itself - the head of the snake
   ///        is in the same position with one of the other segments.
   /// @return 
   bool IsEatingItself() const;
   /// @brief Get the head position of the snake.
   /// @return 
   Point GetHead() const;
   /// @brief Get the last segment of the snake.
   /// @return 
   Point GetTail() const;
   /// @brief Get the segments of the snake.
   /// @return 
   const std::deque<Point>& GetSegments() const;
};
