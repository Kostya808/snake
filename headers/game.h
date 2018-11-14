#ifndef GAME_H
#define GAME_H

#include <class_field.h>
#include <class_fruit.h>
#include <cstdio>
#include <iostream>

class Game
{
private:
    int flag1;
    int flag2;
    int flag3;
    int pause;
    int fast1;
    int fast2;

public:
    Game();
    void game();
    int loser();

};

#endif