#pragma once

#include <cmath>
#include <iostream>
#include <time.h>
#include <utility>
#include <vector>
#include <string>
#include <stdlib.h>

enum eCompassDirection {STOP = 0, NW, W, SW, NE, E, SE};

class Ball
{
public:

    /**
     * @brief Initializes a ball with input values
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
   friend std::ostream& operator<<(std::ostream& os, Ball ball);

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
     * @brief Initializes a paddle with input values
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
   friend std::ostream& operator<<(std::ostream& os, Paddle paddle);

private:
    int mX;
    int mY;
    int mOriginalX;
    int mOriginalY;
};
