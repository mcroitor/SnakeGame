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
