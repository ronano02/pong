#pragma once

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <stdlib.h>

enum compassDirection {N = 0, NE = 45, E = 90, SE = 135,
                       S = 180, SW = 225, W = 270, NW = 315, NA = -1};

class Ball
{
public:
    /**
     * @brief Initializes the ball with default values
     * @return none
     */
    Ball();

    /**
     * @brief Initializes the ball with input values
     * @param int x - x position
     * @param int y - y position
     * @return none
     */
    Ball(int x, int y);
    
    /**
     * @brief Ball destructor
     * @return none
     */
    ~Ball();

    /**
     * @brief Gets the current position of the ball
     * @return pair of coordinates {x,y}
    */
    std::pair<int, int> getBallPosition();

    /**
     * @brief Gets the current speed of the ball
     * @return int value of the ball's speed
    */
    int getBallSpeed();

    /**
     * @brief Gets the current direction of the ball
     * @return std::string direction- direction of the ball
    */
   compassDirection getBallDirection();

    /**
     * @brief Moves the ball using a given direction and speed
     * @param std::string direction - direction of the ball
     * @param int speed - speed of the ball
     * @return none
    */
    void moveBall(compassDirection direction, int speed);

    /**
     * @brief Generates a random direction in a given side of the field
     * and moves the ball using that direction and a given speed
     * @param std::string side - the side of the map to serve the ball
     * @param int speed - speed to move the ball
    */
   void randomisedMoveBall(std::string side, int speed);

private:
    int mX;
    int mY;
    int mSpeed;
    compassDirection mDirection;
};

class GameController
{
public:
    /**
     * @brief Initializes the game controller with default values
     * @return none
     */
    GameController();

    /**
     * @brief Initializes the game controller with input values
     * @return none
     */
    GameController(int x, int y);

    /**
     * @brief GameController destructor
     */
    ~GameController();

    /**
     * @brief draws the game map to console
     */
    void draw();

private:
    int mWidth;
    int mHeight;
    Ball mBall;
};
