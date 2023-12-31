#include <iostream>
#include "painter.hpp"

void Painter::SetCursor(const Point &point) {
    std::cout << "\x1b[" << point.y << ";" << point.x << "H";
}

void Painter::DrawImage(
    const Point &topLeft,
    const std::vector<std::string> &image)
{
    for(int y = 0; y < image.size(); y++){
        WriteText(Point(topLeft.x, topLeft.y + y), image[y]);
    }

}

void Painter::WriteText(const Point &position, const std::string &text)
{
    SetCursor(position);
    std::cout << text;
}

void Painter::ClearBlock(const Point &topLeft, const Point &bottomRight)
{
    std::string empty(bottomRight.x - topLeft.x, ' ');
    for(int y = 0; y < bottomRight.y - topLeft.y; y++){
        WriteText(Point(topLeft.x, topLeft.y + y), empty);
    }
}
