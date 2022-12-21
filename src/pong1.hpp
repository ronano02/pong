#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

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
    int mHeight;
    int mWidth;
};
