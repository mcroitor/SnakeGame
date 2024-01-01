#pragma once

#include <string>
#include <vector>
#include "point.hpp"

class Painter {
   static void SetCursor(const Point& point);
public:
   static void DrawImage(
      const Point& topLeft, 
      const std::vector<std::string>& image);
   static void WriteText(const Point& position, const std::string& text);
   static void ClearBlock(const Point& topLeft, const Point& bottomRight);
};
