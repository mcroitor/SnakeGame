#pragma once

#include <string>
#include <vector>
#include "point.hpp"

struct AbstractPainter {
   virtual void DrawImage(
      const Point& topLeft, 
      const std::vector<std::string>& image) const = 0;
   virtual void WriteText(const Point& position, const std::string& text) const = 0;
};
