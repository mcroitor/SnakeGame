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
   //         one segment, at the position (1, 1).
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
