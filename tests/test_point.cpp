#include <catch_amalgamated.hpp>

#include <point.hpp>

TEST_CASE("Point class tests", "[point]") {
    SECTION("Default constructor") {
        Point p;
        REQUIRE(p.x == 0);
        REQUIRE(p.y == 0);
    }

    SECTION("Constructor with parameters") {
        Point p(1, 2);
        REQUIRE(p.x == 1);
        REQUIRE(p.y == 2);
    }

    SECTION("Copy constructor") {
        Point p1(1, 2);
        Point p2(p1);
        REQUIRE(p2.x == 1);
        REQUIRE(p2.y == 2);
    }

    SECTION("Copy assignment operator") {
        Point p1(1, 2);
        Point p2;
        p2 = p1;
        REQUIRE(p2.x == 1);
        REQUIRE(p2.y == 2);
    }

    SECTION("Equality operator") {
        Point p1(1, 2);
        Point p2(1, 2);
        REQUIRE(p1 == p2);
    }

    SECTION("Read from stream") {
        Point p;
        std::istringstream in("1 2");
        in >> p;
        REQUIRE(p.x == 1);
        REQUIRE(p.y == 2);
    }

    SECTION("Write to stream") {
        Point p(1, 2);
        std::ostringstream out;
        out << p;
        REQUIRE(out.str() == "1 2");
    }
}