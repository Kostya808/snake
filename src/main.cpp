#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>
#include <game.h>

int main() {
	Game g;
	g.game();
	endwin();
	g.loser();
	return 0;
}