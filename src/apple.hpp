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
 * @file apple.hpp
 * @details The part of Snake Game project, is created as a support sample
 *          for the `C++ Development` course for Game Design specialization.
 * @brief This file contains the definition of the Apple class.
 * @author Mihail Croitor <mcroitor@gmail.com>
 * @date 2024
 */
#pragma once

#include <iostream>
#include "point.hpp"

class Apple {
   Point _position;
public:
   /// @brief Default constructor.
   Apple();

   /// @brief Constructor with parameters, allows to set the position of the apple.
   /// @param position 
   Apple(const Point& position);

   /// @brief Copy constructor.
   /// @param other 
   Apple(const Apple& other);

   /// @brief Allows to check apple's position.
   /// @return position of the apple.
   Point GetPosition() const;

   /// @brief Copy assignment operator.
   /// @param other 
   /// @return 
   Apple operator = (const Apple& other);

   /// @brief Comparison operator.
   /// @param other 
   /// @return 
   bool operator == (const Apple& other) const;
};

/// @brief Read apple object from input stream.
/// @param in 
/// @param apple 
/// @return 
std::istream& operator >> (std::istream& in, Apple& apple);

/// @brief Write apple object to output stream.
/// @param out 
/// @param apple 
/// @return 
std::ostream& operator << (std::ostream& out, const Apple& apple);
