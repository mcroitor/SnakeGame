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
 * @file painter.cpp
 * @details The part of Snake Game project, is created as a support sample
 *          for the `C++ Development` course for Game Design specialization.
 * @brief This file contains something for drawing on the screen.
 * @author Mihail Croitor <mcroitor@gmail.com>
 * @date 2024
 */
#include "painter.hpp"

void Painter::SetCursorPosition(int x, int y) const {
    std::cout << "\033[" << y << ";" << x << "H";
}

void Painter::DrawImage(
    Point topLeft,
    Point bottomRight,
    const std::vector<std::string> &image) const
{
    for(int i = 0; i < image.size(); ++i) {
        SetCursorPosition(topLeft.x, topLeft.y + i);
        std::cout << image[i];
    }
}

void Painter::WriteText(Point position, const std::string &text) const {
    SetCursorPosition(position.x, position.y);
    std::cout << text;
}
