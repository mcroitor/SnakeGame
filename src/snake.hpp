#pragma once

#include <deque>
#include "apple.hpp"
#include "direction.hpp"
#include "point.hpp"

class Snake
{
   static const int MAX_SIZE = 100;
   std::deque<Point> _segments;
   int _nr_segments;

public:
   Snake();
   Snake(const Point &position);
   void Move(Direction direction);
   int GetSize() const;
   Point GetHead() const;
   Point GetTail() const;
   const std::deque<Point> &GetSegments() const;
   void Eat(const Apple &apple);
   bool IsDead() const;
};
