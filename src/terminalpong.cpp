#include "terminalpong.hpp"

//------------------------------------------------------------------------------
// Ball Functions
//------------------------------------------------------------------------------

Ball::Ball(int x, int y) : mX(x), mY(y), mOriginalX(x),
                           mOriginalY(y), mDirection(STOP) {}

Ball::~Ball() {}

void Ball::setDirection(eCompassDirection direction)
{
    mDirection = direction;
}

void Ball::randomiseDirection()
{
    setDirection((eCompassDirection)((rand() % 6) + 1));
}

void Ball::move()
{
    switch (mDirection)
    {
    case STOP:
        break;
    case NW:
        mX--;
        mY--;
        break;
    case W:
        mX--;
        break;
    case SW:
        mX--;
        mY++;
        break;
    case NE:
        mX++;
        mY--;
        break;
    case E:
        mX++;
        break;
    case SE:
        mX++;
        mY++;
        break;
    default:
        std::cout << "Error: Invalid direction in Ball.move()" << std::endl;
    }
}

void Ball::reset()
{
    mX = mOriginalX;
    mY = mOriginalY;
    mDirection = STOP;
}

std::ostream &operator<<(std::ostream &os, Ball ball)
{
    os << "Ball Position: [" << ball.mX << ", " << ball.mY << "]\n"
       << "Ball Direction: [" << ball.mDirection << "]\n";
    return os;
}

//------------------------------------------------------------------------------
// Paddle Functions
//------------------------------------------------------------------------------

Paddle::Paddle(int x, int y) : mX(x), mY(y), mOriginalX(x), mOriginalY(y) {}

Paddle::~Paddle() {}

void Paddle::reset()
{
    mX = mOriginalX;
    mY = mOriginalY;
}

std::ostream &operator<<(std::ostream &os, Paddle paddle)
{
    os << "Paddle Position: [" << paddle.mX << ", " << paddle.mY << "]\n";
    return os;
}

//------------------------------------------------------------------------------
// Controller Functions
//------------------------------------------------------------------------------

Controller::Controller(int height, int width)
{
    mHeight = height;
    mWidth = width;
    quitGame = false;
    ball = new Ball(height / 2, width / 2);
    playerA = new Paddle(1, height / 2 - 3);
    playerB = new Paddle(width - 2, height / 2 - 3);
}

//------------------------------------------------------------------------------

int main()
{
    return 0;
}