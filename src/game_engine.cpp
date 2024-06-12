#include <thread>
#include <chrono>
#include <iostream>
#include <windows.h>

#include "game_engine.hpp"

const size_t MAX_TIME_MS = 200000;
const size_t DELTA_MS = 10000;

GameEngine::GameEngine() : _apple_color{usm::graphics::ForegroundColor::Red},
                           _snake_color{usm::graphics::ForegroundColor::Green},
                           _background_color{usm::graphics::BackgroundColor::Black},
                           _text_color{usm::graphics::ForegroundColor::White},
                           _status_bar_color{usm::graphics::BackgroundColor::Blue},
                            _score {0},
                            _speed {1}
{
    _board = Board(80, 24);
    _apple = Apple(_board.GetRandomPosition());
    _snake = Snake({1, 1});
}

GameEngine::~GameEngine() {
    tuia::SetBackgroundColor(background_color::Black);
    tuia::SetForegroundColor(foreground_color::White);
    tuia::ClearScreen();
}

void GameEngine::Init()
{
    tuia::SetBackgroundColor(background_color::Green);
    tuia::ClearBlock({1, 1}, _board.GetWidth() + 2, _board.GetHeight() + 2);
    tuia::SetBackgroundColor(_background_color);
    tuia::SetForegroundColor(_text_color);
    tuia::ClearBlock({2, 2}, _board.GetWidth(), _board.GetHeight());
    DrawApple();
    DrawSnake();
    UpdateStatus();
}

void GameEngine::DrawApple() const
{
    tuia::SetForegroundColor(_apple_color);
    tuia::WriteLine({_apple.GetPosition().x + 2u, _apple.GetPosition().y + 2u}, "@");
}

void GameEngine::DrawSnake() const
{
    tuia::SetForegroundColor(_snake_color);
    for (const Point &segment : _snake.GetSegments())
    {
        tuia::WriteLine({segment.x + 2u, segment.y + 2u}, "O");
    }
}

bool GameEngine::GameOver() const
{
    return //_snake.IsDead() ||
            (_snake.GetHead().x < 0 ||
            _snake.GetHead().x >= _board.GetWidth() ||
            _snake.GetHead().y < 0 ||
            _snake.GetHead().y >= _board.GetHeight());
}

char GameEngine::GetEvent() const
{
    if (
        (GetAsyncKeyState(VK_UP) & 0x8000) ||
        (GetAsyncKeyState('W') & 0x8000) ||
        (GetAsyncKeyState('w') & 0x8000))
    {
        return 'w';
    }
    if (
        (GetAsyncKeyState(VK_DOWN) & 0x8000) ||
        (GetAsyncKeyState('S') & 0x8000) ||
        (GetAsyncKeyState('s') & 0x8000))
    {
        return 's';
    }
    if (
        (GetAsyncKeyState(VK_LEFT) & 0x8000) ||
        (GetAsyncKeyState('A') & 0x8000) ||
        (GetAsyncKeyState('a') & 0x8000))
    {
        return 'a';
    }
    if (
        (GetAsyncKeyState(VK_RIGHT) & 0x8000) ||
        (GetAsyncKeyState('D') & 0x8000) ||
        (GetAsyncKeyState('d') & 0x8000))
    {
        return 'd';
    }
    if (
        (GetAsyncKeyState(VK_ESCAPE) & 0x8000) ||
        (GetAsyncKeyState('Q') & 0x8000) ||
        (GetAsyncKeyState('q') & 0x8000))
    {
        return 'q';
    }

    return ' ';
}

void GameEngine::UpdateScreen() const
{
    DrawApple();
    DrawSnake();
}

void GameEngine::UpdateStatus() const
{
    std::string _status_message = std::string("Score: ") + 
        std::to_string(_score) + 
        std::string(" Speed: ") + 
        std::to_string(_speed);
    point pt{1u, _board.GetHeight() + 3u};
    tuia::SetBackgroundColor(_status_bar_color);
    tuia::ClearBlock(pt, _board.GetWidth() + 2, 1);
    tuia::WriteLine(pt, _status_message);
}

void GameEngine::Run()
{
    Direction direction = Direction::Right;
    while (!GameOver())
    {
        char event = GetEvent();
        switch (event)
        {
        case 'w':
            direction = Direction::Top;
            break;
        case 's':
            direction = Direction::Bottom;
            break;
        case 'a':
            direction = Direction::Left;
            break;
        case 'd':
            direction = Direction::Right;
            break;
        case 'q':
            return;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(MAX_TIME_MS - _speed * DELTA_MS));
        auto oops = _snake.GetTail();
        _snake.Move(direction);
        if(_snake.GetHead() == _apple.GetPosition()) {
            _snake.Eat(_apple);
            _apple = Apple(_board.GetRandomPosition());
            _score += 10;
            ++_speed;
        }

        tuia::SetBackgroundColor(_background_color);
        tuia::ClearLine({oops.x + 2u, oops.y + 2u}, 2);
        UpdateScreen();
        UpdateStatus();
        std::cout << std::endl;
    }
}
