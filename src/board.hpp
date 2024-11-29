#pragma once

#include <iostream>
#include <string>

#include "point.hpp"

class Board {
   int _width;
   int _height;
public:
   /// @brief Board constructor, allows to set the width and height of the board.
   /// @param width default value is 20
   /// @param height default value is 20
   Board(int width = 20, int height = 20);

   /// @brief Copy constructor
   /// @param other 
   Board(const Board& other);

   /// @brief Returns the width of the board.
   /// @return 
   int GetWidth() const;

   /// @brief Returns the height of the board.
   int GetHeight() const;

   /// @brief Generates a random position within the board.
   /// @return 
   Point GetRandomPosition() const;

   /// @brief Returns a string with the information of the board.
   /// @return 
   std::string GetInfo() const;

   /// @brief Copy operator
   /// @param other 
   /// @return 
   Board operator = (const Board& other);

   /// @brief Compares two boards.
   bool operator == (const Board& other) const;
};

/// @brief Reads the board object from the input stream.
/// @param in 
/// @param board 
/// @return 
std::istream& operator >> (std::istream& in, Board& board);

/// @brief Writes the board object to the output stream.
/// @param out 
/// @param board 
/// @return 
std::ostream& operator << (std::ostream& out, const Board& board);
