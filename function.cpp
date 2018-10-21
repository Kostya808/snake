#include <ncurses.h>
#include "class_field.h"
#include "class_head.h"

void print(Fields * s, Head * h1, Head * h2) {
	initscr();
	clear();
	int i, j;
	for(i = 0; i < s->size; i++) {
		for(j = 0; j < s->size; j++) {
			if(s->snake_matrix[i][j] == h1->type_head)
				printw("@ ");
            else if(s->snake_matrix[i][j] == h2->type_head)
                printw("Q ");
			else if(s->snake_matrix[i][j] == h1->type_body)
                printw("O ");
            else if(s->snake_matrix[i][j] == h2->type_body)
                printw("0 ");
            else if(s->snake_matrix[i][j] == 3)
                printw("A ");
            else if(s->snake_matrix[i][j] == 4)
                printw("B ");
            else if(s->snake_matrix[i][j] == 5)
                printw("##");
            else
				printw("  ");
		}
		printw("\n");
	}
        printw("Score player 1: %d\n", h1->score);
        printw("Score player 2: %d\n", h2->score);
    endwin();
}

int kbhit(){
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

void control(Head *h1, Head*h2) {
	noecho(); 
	keypad(stdscr, true); 
	cbreak();
    nodelay(stdscr, TRUE);
	if(kbhit() == 1) {
        switch(getch()){
            case KEY_UP:
      	        h1->course = 't';
                break;
            case KEY_DOWN:
      	        h1->course = 'd';
                break;
            case KEY_RIGHT:
      	        h1->course = 'r';
                break;
            case KEY_LEFT:
      	        h1->course = 'l';
                break;
            case 119:
                h2->course = 't';
                break;
            case 115:
                h2->course = 'd';
                break;
            case 100:
                h2->course = 'r';
                break;
            case 97:
                h2->course = 'l';
                break;
        }
	}
}

int automotion(Fields * s, Head *h) {
	if(h->course == 't') 
      		h->new_x = h->x - 1;
	if(h->course == 'd') 
      		h->new_x = h->x + 1;
	if(h->course == 'r') 
     		h->new_y = h->y + 1;
	if(h->course == 'l') 
      		h->new_y = h->y - 1;
    if((s->snake_matrix[h->new_x][h->new_y] != 0 && 
        s->snake_matrix[h->new_x][h->new_y] != 3 &&
        s->snake_matrix[h->new_x][h->new_y] != 4)) {
        if(h->new_x == h->next->x && h->new_y == h->next->y) {
            if(h->course == 't') {
                h->new_x = h->x + 1;
                h->new_y = h->y;
                h->course = 'd';
            }
            else if(h->course == 'd') {
                h->new_x = h->x - 1;
                h->new_y = h->y;
                h->course = 't';
            }
            else if(h->course == 'r') {
                h->new_x = h->x;
                h->new_y = h->y - 1;
                h->course = 'l';
            }
            else {
                h->new_x = h->x;
                h->new_y = h->y + 1;
                h->course = 'r';
            }
        }
        else
            return 0;
    }
    return 1;
}

int check_head(Head *h1, Head *h2) {
    if(h1->x == h2->x && h1->y == h2->y) {
        return 0;
    }
    return 1;
}