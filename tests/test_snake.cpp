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

TEST_CASE("Snake eats an apple", "[snake]") {
    Point position{5, 5};
    Point apple_position{position.x + 1, position.y};
    Snake snake(position);
    Apple apple{apple_position};
    REQUIRE(snake.GetSize() == 1);
    snake.Eat(apple);
    REQUIRE(snake.GetSize() == 1);
    snake.Move(Direction::Right);
    snake.Eat(apple);
    REQUIRE(snake.GetSize() == 2);
    REQUIRE(snake.GetHead() == apple_position);
    REQUIRE(snake.IsEatingItself() == false);
    snake.Move(Direction::Right);
    REQUIRE(snake.IsEatingItself() == false);
}