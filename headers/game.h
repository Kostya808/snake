#ifndef GAME_H
#define GAME_H

class Game
{
private:
    int flag1;
    int flag2;
    int flag3;
    int pause;
    int fast1;
    int fast2;
    int m;
public:
    Game();
    void game();
    void loser();
};

#endif