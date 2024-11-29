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
