#include <catch_amalgamated.hpp>
#include <direction.hpp>

TEST_CASE("Constructor with direction", "[direction]") {
    Direction direction {Direction::Bottom};
    REQUIRE(direction == Direction::Bottom);
}

TEST_CASE("Operator <<", "[direction]") {
    std::ostringstream oss;
    oss << Direction::Left;
    REQUIRE(oss.str() == "Left");
    oss.str("");
    oss << Direction::Right;
    REQUIRE(oss.str() == "Right");
    oss.str("");
    oss << Direction::Top;
    REQUIRE(oss.str() == "Top");
    oss.str("");
    oss << Direction::Bottom;
    REQUIRE(oss.str() == "Bottom");
}
