#include "function.h"
#include <stdio.h>
#include <ncurses.h>
#include <string.h>


void print(Fields * s) {
	initscr();
	clear();
	int i, j;
	for(i = 0; i < s->size; i++) {
		for(j = 0; j < s->size; j++) {
			if(s->snake_matrix[i][j] == 1)
				printw("@ ");
			else
				printw("  ", s->snake_matrix[i][j]);
			if(j == s->size - 1)
				printw("|");
		}
		printw("\n");
	}
	printw("-----------------------------------------\n");
    endwin();
}

int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

void control(Fields * s) {
	noecho(); 
	keypad(stdscr, true); 
	cbreak();
    nodelay(stdscr, TRUE);
	if(kbhit() == 1) {
    switch(getch()){
      case KEY_UP:
      	s->head.course = 't';
        break;
      case KEY_DOWN:
      	s->head.course = 'd';
        break;
      case KEY_RIGHT:
      	s->head.course = 'r';
        break;
      case KEY_LEFT:
      	s->head.course = 'l';
        break;
    }
	}
}

void automotion(Fields * s) {
	if(s->head.course == 't') {
      	if(s->head.x == 0)
      		s->head.new_x = s->size - 1;
      	else
      		s->head.new_x = s->head.x - 1;
    }
	if(s->head.course == 'd') {
      	if(s->head.x == s->size - 1)
      		s->head.new_x = 0;
      	else
      		s->head.new_x = s->head.x + 1;
    }
	if(s->head.course == 'r') {
      	if(s->head.y == s->size - 1) 
      		s->head.new_y = 0;
      	else
     		s->head.new_y = s->head.y + 1;
    }
	if(s->head.course == 'l') {
      	if(s->head.y == 0)
      		s->head.new_y = s->size - 1;
      	else
      		s->head.new_y = s->head.y - 1;
    }
}
