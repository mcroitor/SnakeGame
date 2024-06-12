#pragma once

#include <iostream>
#include <string>

#include "point.hpp"

class Board {
   int _width;
   int _height;
public:
   Board(int width = 20, int height = 20);
   Board(const Board& other);
   int GetWidth() const;
   int GetHeight() const;
   Point GetRandomPosition() const;

   Board operator = (const Board& other);
   bool operator == (const Board& other) const;

   std::string Info() const;
};

std::istream& operator >> (std::istream& in, Board& board);
std::ostream& operator << (std::ostream& out, const Board& board);
