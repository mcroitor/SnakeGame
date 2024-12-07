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
 * @file board.hpp
 * @details The part of Snake Game project, is created as a support sample
 *          for the `C++ Development` course for Game Design specialization.
 * @brief This file contains the declaration of the Board class. This class
 *       is used to define the board size and generate random positions.
 * @author Mihail Croitor <mcroitor@gmail.com>
 * @date 2024
 */
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
