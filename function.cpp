#include "class_field.h"
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
 
void print(Fields * s) {
	initscr();
	clear();
	int i, j;
	for(i = 0; i < s->size; i++) {
		for(j = 0; j < s->size; j++) {
			if(s->snake_matrix[i][j].type == 1)
				printw("@ ");
			else if(s->snake_matrix[i][j].type == 2)
                printw("o ");
            else if(s->snake_matrix[i][j].type == 3)
                printw("a ");
            else if(s->snake_matrix[i][j].type == 4)
                printw("b ");
            else if(s->snake_matrix[i][j].type == 5)
                printw("##");
            else
				printw("  ");
		}
		printw("\n");
	}
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
      	s->head1.course = 't';
        break;
      case KEY_DOWN:
      	s->head1.course = 'd';
        break;
      case KEY_RIGHT:
      	s->head1.course = 'r';
        break;
      case KEY_LEFT:
      	s->head1.course = 'l';
        break;
    }
	}
}

int automotion(Fields * s) {
	if(s->head1.course == 't') 
      		s->head1.new_x = s->head1.x - 1;
	if(s->head1.course == 'd') 
      		s->head1.new_x = s->head1.x + 1;
	if(s->head1.course == 'r') 
     		s->head1.new_y = s->head1.y + 1;
	if(s->head1.course == 'l') 
      		s->head1.new_y = s->head1.y - 1;
    if(s->snake_matrix[s->head1.new_x][s->head1.new_y].type != 0 && 
        s->snake_matrix[s->head1.new_x][s->head1.new_y].type != 3 &&
        s->snake_matrix[s->head1.new_x][s->head1.new_y].type != 4) 
        return 0;
    return 1;
}

