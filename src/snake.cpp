#include "snake.hpp"

#include <algorithm>

Snake::Snake(): _nr_segments{1}, _segments{1, {1, 1}}  {}

Snake::Snake(const Point &_position): _nr_segments{1}, _segments{1, _position} {}

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
    auto head = GetHead();
    return std::find(_segments.begin() + 1, _segments.end(), head) != _segments.end();
}
