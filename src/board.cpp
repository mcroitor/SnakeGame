#include <random>

#include "board.hpp"

std::mt19937 random_engine(std::random_device{}());

Board::Board(int width, int height) : _width(width), _height(height) {}

Board::Board(const Board &other) : _width(other.GetWidth()), _height(other.GetHeight()) {}

int Board::GetWidth() const
{
    return _width;
}

int Board::GetHeight() const
{
    return _height;
}

Board Board::operator=(const Board &other)
{
    _width = other.GetWidth();
    _height = other.GetHeight();
    return *this;
}

bool Board::operator==(const Board &other) const
{
    return GetWidth() == other.GetWidth() && GetHeight() == other.GetHeight();
}

std::string Board::Info() const {
    return std::string("[") + 
        std::to_string(_width) + 
        ", " + 
        std::to_string(_height) + 
        std::string("]");
}

Point Board::GetRandomPosition() const
{
    return Point(
        std::uniform_int_distribution<int>(0, _width - 1)(random_engine),
        std::uniform_int_distribution<int>(0, _height - 1)(random_engine)
    );
}

std::istream &operator>>(std::istream &in, Board &board)
{
    int width, height;
    in >> width >> height;
    board = Board(width, height);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Board &board)
{
    out << board.Info();
    return out;
}
