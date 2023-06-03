#ifndef ICYTOWER_GAMERUNNER_H
#define ICYTOWER_GAMERUNNER_H

#include "Game.h"



class GameRunner {
public:
    explicit GameRunner();
    int start();


private:
    int score;
    int highScore;
};


#endif //ICYTOWER_GAMERUNNER_H
