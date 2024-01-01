#include "snake.hpp"

Snake::Snake(): _nr_segments(1) {}
Snake::Snake(const Point &position): _nr_segments(1) {
    _segments[0] = position;
}
void Snake::Move(Direction direction) {}
int Snake::GetSize() const {
    return _nr_segments;
}
Point Snake::GetPosition() const {
    return _segments[0];
}
void Snake::Eat(const Apple &apple) {}