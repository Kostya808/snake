#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>
#include <game.h>

int main() {
	Game g;
	g.game();
    endwin();//выход из ncurses
	g.loser();
	return 0;
}