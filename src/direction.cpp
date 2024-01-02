#include <map>
#include "direction.hpp"

std::ostream& operator<<(std::ostream& out, const Direction& direction){
    std::map<Direction, std::string> directions {
        {Direction::Left, std::string("Left")},
        {Direction::Right, std::string("Right")},
        {Direction::Top, std::string("Top")},
        {Direction::Bottom, std::string("Bottom")},
    };
    out << directions[direction];
    return out;
}