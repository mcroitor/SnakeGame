#pragma once

#include <vector>
#include <string>
#include "point.hpp"

struct AbstractPainter {
   /// @brief Draw an image on the screen in the specified area.
   /// @param topLeft top left corner of the screen area to draw the image.
   /// @param bottomRight bottom right corner of the screen area to draw the image.
   /// @param image ASCII art image to draw.
   virtual void DrawImage(
      Point topLeft,
      Point bottomRight,
      const std::vector<std::string>& image) const = 0;

   /// @brief Write text on the screen at the specified position.
   /// @param position position to write the text.
   /// @param text a string to write on the screen.
   virtual void WriteText(Point position, const std::string& text) const = 0;
};
