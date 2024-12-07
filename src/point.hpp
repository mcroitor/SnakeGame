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
 * @file point.hpp
 * @details The part of Snake Game project, is created as a support sample
 *          for the `C++ Development` course for Game Design specialization.
 * @brief This file contains simple point structure definition.
 * @author Mihail Croitor <mcroitor@gmail.com>
 * @date 2024
 */
#pragma once

#include <iostream>

struct Point{
   /// @brief The x coordinate of the point.
   int x;
   /// @brief The y coordinate of the point.
   int y;

   /// @brief Construct a new Point object
   /// @param _x 
   /// @param _y 
   Point(int _x = 0, int _y = 0);
   /// @brief Copy constructor
   /// @param other 
   Point(const Point& other);
   /// @brief Move constructor
   Point(Point&& other) noexcept;

   /// @brief Copy assignment operator
   /// @param other
   /// @return Point
   Point operator = (const Point& other);
   /// @brief Move assignment operator
   /// @param other 
   /// @return Point
   Point operator = (Point&& other) noexcept;
   /// @brief Compare two points
   /// @param other 
   /// @return 
   bool operator == (const Point& other) const;
};

/// @brief Read a point from the input stream.
/// @param in 
/// @param point 
/// @return 
std::istream& operator >> (std::istream& in, Point& point);
/// @brief Write a point to the output stream.
/// @param out 
/// @param point 
/// @return 
std::ostream& operator << (std::ostream& out, const Point& point);
