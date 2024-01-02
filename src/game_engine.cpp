#include "game_engine.hpp"
#include "painter.hpp"

GameEngine::GameEngine() {
    _board = Board(10, 10);
}
void GameEngine::Init() {
    std::vector<std::string> board(
        _board.GetWidth(),
        std::string(_board.GetHeight(), '+'));
    Painter::DrawImage(Point(0, 0), board);
    //std::cout << _board << std::endl;
}
void GameEngine::Run() {}