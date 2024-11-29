#include <catch_amalgamated.hpp>
#include <apple.hpp>

TEST_CASE("Default constructor", "[apple]") {
    Apple apple;
    REQUIRE(apple.GetPosition() == Point(0, 0));
}

TEST_CASE("Constructor with position", "[apple]") {
    Apple apple(Point(1, 2));
    REQUIRE(apple.GetPosition() == Point(1, 2));
}

TEST_CASE("Copy constructor", "[apple]") {
    Apple apple(Point(1, 2));
    Apple apple2(apple);
    REQUIRE(apple2.GetPosition() == Point(1, 2));
}

TEST_CASE("Assignment operator", "[apple]") {
    Apple apple(Point(1, 2));
    Apple apple2;
    apple2 = apple;
    REQUIRE(apple2.GetPosition() == Point(1, 2));
}

TEST_CASE("Equality operator", "[apple]") {
    Apple apple(Point(1, 2));
    Apple apple2(Point(1, 2));
    REQUIRE(apple == apple2);
}

TEST_CASE("read and write", "[apple]") {
    std::stringstream ss;
    Apple apple(Point(1, 2));
    ss << apple;
    REQUIRE(ss.str() == "1 2");

    ss.str("3 4");
    ss >> apple;
    REQUIRE(apple.GetPosition() == Point(3, 4));
}