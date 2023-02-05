#pragma once

#include <cmath>
#include <iostream>
#include <time.h>
#include <utility>
#include <vector>
#include <string>
#include <stdlib.h>

enum eCompassDirection
{
    STOP = 0,
    NW,
    W,
    SW,
    NE,
    E,
    SE
};

class Ball
{
public:
    /**
     * @brief Consructs a ball with input values
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
     * @brief Sets the direction of the ball to a given direction
     * @param eCompassDirection direction - the desired direction
     * @return none
     */
    void setDirection(eCompassDirection direction);

    /**
     * @brief Sets the direction of the ball to a random direction
     * @return none
     */
    void randomiseDirection();

    /**
     * @brief Gets the current x position of the ball
     * @return int x position
     */
    inline int getXPos() { return mX; }

    /**
     * @brief Gets the current y position of the ball
     * @return int y position
     */
    inline int getYPos() { return mY; }

    /**
     * @brief Gets the current direction of the ball
     * @return eCompassDirection direction
     */
    inline eCompassDirection getDirection() { return mDirection; }

    /**
     * @brief Based on the direction of the ball, move the ball
     * @return none
     */
    void move();

    /**
     * @brief returns the ball to its original position and stops movement
     * @return none
     */
    void reset();

    /**
     * @brief Writes the current position and direction of the ball
     * to the output stream
     * @param os - output stream
     * @param ball - Ball
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, Ball ball);

private:
    int mX;
    int mY;
    int mOriginalX;
    int mOriginalY;
    eCompassDirection mDirection;
};

class Paddle
{
public:
    /**
     * @brief Consructs a paddle with input values
     * @param int x - x position
     * @param int y - y position
     * @return none
     */
    Paddle(int x, int y);

    /**
     * @brief Paddle destructor
     * @return none
     */
    ~Paddle();

    /**
     * @brief Gets the current x position of the paddle
     * @return int x position
     */
    inline int getXPos() { return mX; }

    /**
     * @brief Gets the current y position of the paddle
     * @return int y position
     */
    inline int getYPos() { return mY; }

    /**
     * @brief Moves the paddle up
     * @return none
     */
    inline void moveUp() { mY--; }

    /**
     * @brief Moves the paddle down
     * @return none
     */
    inline void moveDown() { mY++; }

    /**
     * @brief returns the paddle to its original position
     * @return none
     */
    void reset();

    /**
     * @brief Writes the current position of the paddle to the output stream
     * @param os - output stream
     * @param paddle - Paddle
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, Paddle paddle);

private:
    int mX;
    int mY;
    int mOriginalX;
    int mOriginalY;
};

class Controller
{
public:
    /**
     * @brief Consructs a game controller with given map height and width
     * @param int height - height of map
     * @param int width - width of map
     * @return none
     */
    Controller(int height, int width);

    /**
     * @brief Controller destructor
     * @return none
     */
    ~Controller();

    /**
     * @brief Adds one point to a given players score
     * @param Paddle*player - pointer to the player
     * @return none
     */
    void addPoint(Paddle *player);

    /**
     * @brief Prints the game (map, paddles, ball, etc...) to the screen
     * @return none
     */
    void printGame();

    /**
     * @brief Interprets user input and moves appropriate paddle if neccessary
     * @return none
     */
    void playerInput();

    /**
     * @brief Decides if the ball needs to change directions such as if it has
     * been hit by a paddle. Also, determines if the score needs to be updated
     * @return none
     */
    void gameBrain();

    /**
     * @brief Starts and runs the game loop
     * @return none
     */
    void run();

private:
    int mHeight;
    int mWidth;
    int scoreA = 0;
    int scoreB = 0;
    bool quitGame;
    Ball *ball;

    Paddle *playerA;
    Paddle *playerB;
    char upA = 'w';
    char downA = 's';
    char upB = 'i';
    char downB = 'k';
};
