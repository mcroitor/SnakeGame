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
 * @file apple.hpp
 * @details The part of Snake Game project, is created as a support sample
 *          for the `C++ Development` course for Game Design specialization.
 * @brief No comments.
 * @author Mihail Croitor <mcroitor@gmail.com>
 * @date 2024
 */
#include "point.hpp"

Point::Point(int _x, int _y) : x(_x), y(_y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::Point(Point &&other) noexcept : x(other.x), y(other.y) {}

Point Point::operator=(const Point &other)
{
    x = other.x;
    y = other.y;
    return *this;
}

Point Point::operator=(Point &&other) noexcept
{
    x = other.x;
    y = other.y;
    return *this;
}

bool Point::operator==(const Point &other) const
{
    return x == other.x && y == other.y;
}

std::istream& operator >> (std::istream& in, Point& point){
    int x, y;
    in >> x >> y;
    point = Point(x, y);
    return in;
}

std::ostream& operator << (std::ostream& out, const Point& point){
    out << point.x << " " << point.y;
    return out;
}
