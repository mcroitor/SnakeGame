#include <catch_amalgamated.hpp>
#include <board.hpp>

TEST_CASE("Default constructor", "[board]") {
    Board board;
    REQUIRE(board.GetWidth() == 20);
    REQUIRE(board.GetHeight() == 20);
}

TEST_CASE("Constructor with width and height", "[board]") {
    Board board(10, 20);
    REQUIRE(board.GetWidth() == 10);
    REQUIRE(board.GetHeight() == 20);
}

TEST_CASE("Copy constructor", "[board]") {
    Board board(10, 20);
    Board board2(board);
    REQUIRE(board2.GetWidth() == 10);
    REQUIRE(board2.GetHeight() == 20);
}

TEST_CASE("Assignment operator", "[board]") {
    Board board(10, 20);
    Board board2;
    board2 = board;
    REQUIRE(board2.GetWidth() == 10);
    REQUIRE(board2.GetHeight() == 20);
}

TEST_CASE("Equality operator", "[board]") {
    Board board(10, 20);
    Board board2(10, 20);
    REQUIRE(board == board2);
}

TEST_CASE("read and write", "[board]") {
    std::stringstream ss;
    Board board(10, 20);
    ss << board;
    REQUIRE(ss.str() == "10 20");

    ss.str("30 40");
    ss >> board;
    REQUIRE(board.GetWidth() == 30);
    REQUIRE(board.GetHeight() == 40);
}