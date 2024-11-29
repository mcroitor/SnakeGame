#include <catch_amalgamated.hpp>

#include <snake.hpp>

TEST_CASE("Snake can be created", "[snake]") {
    Snake snake;
    CAPTURE(snake.GetPosition());
    REQUIRE(snake.GetSize() == 1);
    REQUIRE(snake.GetPosition().x == 1);
    REQUIRE(snake.GetPosition().y == 1);
}

TEST_CASE("Snake can move", "[snake]") {
    Point position{5, 5};
    Snake snake(position);
    // current position is (5, 5)
    INFO("Current position: " << snake.GetPosition());
    REQUIRE(snake.GetPosition() == position);
    snake.Move(Direction::Right);
    REQUIRE(snake.GetPosition() == Point{position.x + 1, position.y});
    snake.Move(Direction::Bottom);
    REQUIRE(snake.GetPosition() == Point{position.x + 1, position.y + 1});
    snake.Move(Direction::Left);
    REQUIRE(snake.GetPosition() == Point{position.x, position.y + 1});
    snake.Move(Direction::Top);
    REQUIRE(snake.GetPosition() == position);
}