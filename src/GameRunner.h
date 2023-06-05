#ifndef ICYTOWER_GAMERUNNER_H
#define ICYTOWER_GAMERUNNER_H

#include "Game.h"



class GameRunner {
    /**
    *   GameRunner is used to setup the environment and includes the game running logic
    */
public:
    explicit GameRunner();
    /**
    *   GameRunner() class constructor
    */
    int start();
    /**
    *   start() method used to start the game
    */

private:
    int score;
    /**
    *   score Stores point value that the current game ended with
    */
    int highScore;
    /**
    *   highScore Stores current session's highest score
    */
};


#endif //ICYTOWER_GAMERUNNER_H
