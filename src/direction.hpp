#pragma once

#include <iostream>

/// @brief The direction in which the snake moves.
enum class Direction {
   Top, Left, Right, Bottom
};

/// @brief Write the direction to the output stream.
/// @param out 
/// @param direction 
/// @return 
std::ostream& operator<<(std::ostream& out, const Direction& direction);
