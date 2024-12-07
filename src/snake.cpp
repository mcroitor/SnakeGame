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
 * @file snake.cpp
 * @details The part of Snake Game project, is created as a support sample
 *          for the `C++ Development` course for Game Design specialization.
 * @brief This file contains the implementation of the Snake class.
 * @author Mihail Croitor <mcroitor@gmail.com>
 * @date 2024
 */
#include "snake.hpp"

#include <algorithm>

Snake::Snake(): _nr_segments{1}, _segments(1, Point(1, 1))  {}

Snake::Snake(const Point &_position): _nr_segments{1}, _segments(1, _position) {}

void Snake::Move(Direction direction) {
    
    Point new_head = _segments[0];
    switch (direction)
    {
    case Direction::Top:
        new_head.y--;
        break;
    case Direction::Bottom:
        new_head.y++;
        break;
    case Direction::Left:
        new_head.x--;
        break;
    case Direction::Right:
        new_head.x++;
        break;
    }
    _segments.push_front(new_head);
    if (_segments.size() > _nr_segments)
    {
        _segments.pop_back();
    }
}

int Snake::GetSize() const {
    return _nr_segments;
}

Point Snake::GetPosition() const {
    return _segments.front();
}
void Snake::Eat(const Apple &apple) {
    if(!(_segments.front() == apple.GetPosition()))
    {
        return;
    }
    _nr_segments++;
    _segments.push_back(_segments.back());
}

Point Snake::GetHead() const {
    return _segments.front();
}

Point Snake::GetTail() const {
    return _segments.back();
}

const std::deque<Point>& Snake::GetSegments() const {
    return _segments;
}

bool Snake::IsEatingItself() const {
    // ugly hack to avoid  first time eating itself
    if(_segments.size() <= 2)
    {
        return false;
    }
    auto head = GetHead();
    return std::find(_segments.begin() + 1, _segments.end(), head) != _segments.end();
}
