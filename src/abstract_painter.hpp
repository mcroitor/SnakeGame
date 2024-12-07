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
 * @details The part of Snake Game project, is created as a support sample
 *          for the `C++ Development` course for Game Design specialization.
 * @file abstract_painter.hpp
 * @brief This file contains the definition of the AbstractPainter struct.
 * @author Mihail Croitor <mcroitor@gmail.com>
 * @date 2024
 */
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
