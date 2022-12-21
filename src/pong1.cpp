#include "pong1.hpp"

GameController::GameController() : mHeight(20), mWidth(50) {}

GameController::GameController(int x, int y) : mHeight(x), mWidth(y) {}

GameController::~GameController() {}

void GameController::draw()
{
    std::system("CLS");
    for (int y = 0; y < mHeight; y++)
    {
        for (int x = 0; x < mWidth; x++)
        {
            if (x == 0)
            {
                std::cout << "\xDB";
            }
            else if (x == mWidth - 1)
            {
                std::cout << "\xDB\n";
            }
            else if (y == 0 || y == mHeight - 1)
            {
                std::cout << "\xDB";
            }
            else
            {
                std::cout << " ";
            }
        }
    }
}

int main()
{
    GameController test = GameController();
    test.draw();
    return 0;
}
