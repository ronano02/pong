#include "terminalpong.hpp"

//----------------------------------------------------------------
// Ball Functions
//----------------------------------------------------------------

Ball::Ball(int x, int y) : mX(x), mY(y), mOriginalX(x), 
                           mOriginalY(y), mDirection(STOP) {}

Ball::~Ball() {}

void Ball::setDirection(eCompassDirection direction) {
    mDirection = direction;
}

void Ball::randomiseDirection() {
    setDirection((eCompassDirection)((rand() % 6) + 1));
}

void Ball::move() {
    switch (mDirection) {
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

void Ball::reset() {
    mX = mOriginalX;
    mY = mOriginalY;
    mDirection = STOP;
}

std::ostream& operator<<(std::ostream& os, Ball ball) {
    os << "Ball Position: [" << ball.mX << "," << ball.mY << "]\n" << 
          "Ball Direction: [" << ball.mDirection << "]\n";
    return os;
}





int main() {
    return 0;
}