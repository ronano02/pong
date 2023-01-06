#include "pong1.hpp"

GameController::GameController() : mWidth(50), mHeight(20), mBall(Ball(mWidth / 2, mHeight / 2)) {}

GameController::GameController(int x, int y) : mWidth(y), mHeight(x) {}

GameController::~GameController() {}

void GameController::draw()
{
    std::system("CLS");
    std::pair<int, int> ballPos = mBall.getBallPosition();
    for (int y = 0; y < mHeight; y++)
    {
        for (int x = 0; x < mWidth; x++)
        {   
            if (x == ballPos.first && y == ballPos.second) {
                std::cout << "O";
                continue;
            }
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

Ball::Ball() : Ball(0, 0) {}

Ball::Ball(int x, int y) : mX(x), mY(y), mSpeed(0), mDirection(NA) {}

Ball::~Ball() {}

std::pair<int, int> Ball::getBallPosition() {return {mX, mY}; }

int Ball::getBallSpeed() { return mSpeed; }

compassDirection Ball::getBallDirection() { return mDirection; }

void Ball::moveBall(compassDirection direction, int speed) {
    mSpeed = speed;
    mDirection = direction;
    switch(direction) {
        case N:
            mDirection = N;
            mY -= 1;
            break;
        case NE:
            mDirection = NE;
            mX += 1;
            mY -= 1;
            break;
        case E:
            mDirection = E;
            mX += 1;
            break;
        case SE:
            mDirection = SE;
            mX += 1;
            mY += 1;
            break;
        case S:
            mDirection = S;
            mY += 1;
            break;
        case SW:
            mDirection = SW;
            mX -= 1;
            mY += 1;
            break;
        case W:
            mDirection = W;
            mX -= 1;
            break;
        case NW:
            mDirection = NW;
            mX -= 1;
            mY -= 1;
            break;
        default:
            std::cout << "Invalid direction @ randomisedMoveBall" << std::endl;
    }
}

void Ball::randomisedMoveBall(std::string side, int speed) {
    int newDirection = std::rand() % 3 + 1;
    if (side == "LS") {
        newDirection *= -1;
    }
    switch(newDirection) {
        case -3:
            moveBall(SW, speed);
            break;
        case -2:
            moveBall(W, speed);
            break;
        case -1:
            moveBall(NW, speed);
            break;
        case 1:
            moveBall(NE, speed);
            break;
        case 2:
            moveBall(E, speed);
            break;
        case 3:
            moveBall(SE, speed);
            break;
        default:
            std::cout << "Invalid direction @ randomisedMoveBall" << std::endl;
    }
}


int main()
{
    GameController test = GameController();
    Ball ballOne = Ball();
    test.draw();
    return 0;
}
