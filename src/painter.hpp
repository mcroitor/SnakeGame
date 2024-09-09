#pragma once

#include "point.hpp"
#include "abstract_painter.hpp"

class Painter: public AbstractPainter {
   void SetCursor(const Point& point) const;
public:
   Painter() = default;

   virtual void DrawImage(
      const Point& topLeft, 
      const std::vector<std::string>& image) const;
   virtual void WriteText(const Point& position, const std::string& text) const;
   void ClearBlock(const Point& topLeft, const Point& bottomRight) const;
};
