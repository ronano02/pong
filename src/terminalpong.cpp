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
    srand(time(NULL));
    mHeight = height;
    mWidth = width;
    quitGame = false;
    ball = new Ball(height / 2, width / 2);
    playerA = new Paddle(1, height / 2 - 3);
    playerB = new Paddle(width - 2, height / 2 - 3);
}

Controller::~Controller()
{
    delete ball;
    delete playerA;
    delete playerB;
}

void Controller::printGame()
{
    std::system("CLS");

    std::cout << '\xDB' << std::string(mWidth, '\xDF') << '\xDB' << std::endl;

    std::pair<int, int> ballPos = ball->getPos();
    std::pair<int, int> posA = playerA->getPos();
    std::pair<int, int> posB = playerB->getPos();

    for (int i = 0; i < mHeight; i++)
    {
        std::cout << "\xDB";
        for (int j = 0; j < mWidth; j++)
        {
            if (ballPos.first == j && ballPos.second == i)
            {
                std::cout << "O";
            }
            else if ((posA.first == j && posA.second <= i && i <= posA.second + 3) ||
                     (posB.first == j && posB.second <= i && i <= posB.second + 3))
            {
                std::cout << "\xBA";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "\xDB" << std::endl;
    }

    std::cout << '\xDB' << std::string(mWidth, '\xDC') << '\xDB' << std::endl;

    std::cout << "Score A: " << scoreA << std::endl;
    std::cout << "Score B: " << scoreB << std::endl;
}

void Controller::playerInput()
{
    ball->move();
    std::pair<int, int> posA = playerA->getPos();
    std::pair<int, int> posB = playerB->getPos();
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            if (posA.second > 0)
                playerA->moveUp();
            break;
        case 'i':
            if (posB.second > 0)
                playerB->moveUp();
            break;
        case 's':
            if (posA.second + 4 < mHeight)
                playerA->moveDown();
            break;
        case 'k':
            if (posB.second + 4 < mHeight)
                playerB->moveDown();
            break;
        case 'q':
            quitGame = true;
            break;
        default:
            break;
        }
        if (ball->getDirection() == STOP)
        {
            ball->randomiseDirection();
        }
    }
}

void Controller::gameBrain()
{
    std::pair<int, int> ballPos = ball->getPos();
    std::pair<int, int> posA = playerA->getPos();
    std::pair<int, int> posB = playerB->getPos();

    // Check if ball hit player A or B
    if ((ballPos.first == posA.first + 1 && ballPos.second >= posA.second && ballPos.second < posA.second + 4) ||
        (ballPos.first == posB.first - 1 && ballPos.second >= posB.second && ballPos.second < posB.second + 4))
    {
        ball->setDirection(static_cast<eCompassDirection>(rand() % 3 + ((ballPos.first == posA.first + 1) ? 4 : 1)));
    }

    // Check if ball hit the walls
    if (ballPos.second == mHeight - 1)
        ball->setDirection(ball->getDirection() == SE ? NE : NW);
    else if (ballPos.second == 0)
        ball->setDirection(ball->getDirection() == NE ? SE : SW);

    // Check if ball reached the ends of the game field
    if (ballPos.first == mWidth - 1)
    {
        scoreA++;
        reset();
    }

    else if (ballPos.first == 0)
    {
        scoreB++;
        reset();
    }

    // Game finishes if a player reaches 10 points
    if (scoreA == 10)
    {   
        printGame();
        std::cout << "\nPlayer A Wins!" << std::endl;
        quitGame = true;
    }
    else if (scoreB == 10)
    {   
        printGame();
        std::cout << "\nPlayer B Wins!" << std::endl;
        quitGame = true;
    }
}

void Controller::run()
{
    while (!quitGame)
    {
        printGame();
        playerInput();
        gameBrain();
    }
}

void Controller::reset()
{
    ball->reset();
    playerA->reset();
    playerB->reset();
}

//------------------------------------------------------------------------------

int main()
{
    Controller gameController(20, 40);
    gameController.run();
    return 0;
}