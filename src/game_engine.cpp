#include <thread>
#include <chrono>

#include "game_engine.hpp"
#include "painter.hpp"

GameEngine::GameEngine()
{
    _board = Board(10, 10);
}
void GameEngine::Init()
{
    UpdateScreen();
    StatusBar();
    // std::cout << _board << std::endl;
}

bool GameEngine::GameOver() const
{
    // TODO: implement this
    return false;
}

char GameEngine::GetEvent() const
{
    return ' ';
}

void GameEngine::UpdateScreen() const {
    std::vector<std::string> board(
        _board.GetWidth(),
        std::string(_board.GetHeight(), '+'));
    Painter::DrawImage(Point(0, 0), board);
}

void GameEngine::StatusBar() const {
    Point point {1, _board.GetHeight() + 2};
    std::string boardStatus = "board: " + _board.Info();
    Painter::WriteText(point, boardStatus);
}
void GameEngine::Run()
{
    while (!GameOver())
    {
        char event = GetEvent();
        switch (event)
        {
        case 'w':
            // TODO: move top
            break;
        case 's':
            // TODO: move bottom
            break;
        case 'a':
            // TODO: move left
            break;
        case 'd':
            // TODO: move right
            break;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        UpdateScreen();
        StatusBar();
    }

}