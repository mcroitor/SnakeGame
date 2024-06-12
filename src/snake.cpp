#include "snake.hpp"

Snake::Snake() : _nr_segments(1), _segments{1, {1, 1}} {
}

Snake::Snake(const Point &position) : _nr_segments(1), _segments {1, position}
{
    _segments[0] = position;
}

void Snake::Move(Direction direction)
{
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

int Snake::GetSize() const
{
    return _nr_segments;
}

Point Snake::GetHead() const
{
    return _segments.front();
}

Point Snake::GetTail() const
{
    return _segments.back();
}

const std::deque<Point> &Snake::GetSegments() const
{
    return _segments;
}

void Snake::Eat(const Apple &apple)
{
    _nr_segments++;
    _segments.push_front(apple.GetPosition());
}

bool Snake::IsDead() const
{
    if(_segments.size() < 2) {
        return false;
    }
    Point head = _segments[0];
    for (int i = 1; i < _segments.size(); i++)
    {
        if (_segments[i] == head)
        {
            return true;
        }
    }
    return false;
}
