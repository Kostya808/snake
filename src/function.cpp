#include <ncurses.h>
#include <class_field.h>
#include <class_head.h>

void print(Fields * s, Head * h1, Head * h2) {
	initscr();
	clear();
	int i, j;
	for(i = 0; i < s->size; i++) {
		for(j = 0; j < s->size; j++) {
			if(s->snake_matrix[i][j] == h1->Get_Type_head())
				printw("K ");
            else if(s->snake_matrix[i][j] == h2->Get_Type_head())
                printw("S ");
			else if(s->snake_matrix[i][j] == h1->Get_Type_body())
                printw("O ");
            else if(s->snake_matrix[i][j] == h2->Get_Type_body())
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
        printw("Score player 1: %d\n", h1->Get_score());
        printw("Score player 2: %d\n", h2->Get_score());
    endwin();
}

int kbhit(){ //Функция проверки на нажатость клавиши
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
      	        h1->Set_Type_head('t');
                break;
            case KEY_DOWN:
      	        h1->Set_Type_head('d');
                break;
            case KEY_RIGHT:
      	        h1->Set_Type_head('r');
                break;
            case KEY_LEFT:
      	        h1->Set_Type_head('l');
                break;
            case 119:
                h2->Set_Type_head('t');
                break;
            case 115:
                h2->Set_Type_head('d');
                break;
            case 100:
                h2->Set_Type_head('r');
                break;
            case 97:
                h2->Set_Type_head('l');
                break;
        }
	}
}

int automotion(Fields * s, Head *h) {
	if(h->Get_Type_head_course() == 't') 
      		h->Set_new_x(h->Get_X() - 1);
	if(h->Get_Type_head_course() == 'd') 
      		h->Set_new_x(h->Get_X() + 1);
	if(h->Get_Type_head_course() == 'r') 
     		h->Set_new_y(h->Get_Y() + 1);
	if(h->Get_Type_head_course() == 'l') 
      		h->Set_new_y(h->Get_Y() - 1);
    if((s->snake_matrix[h->Get_new_x()][h->Get_new_y()] != 0 && //проверка на возможность хода
        s->snake_matrix[h->Get_new_x()][h->Get_new_y()] != 3 &&
        s->snake_matrix[h->Get_new_x()][h->Get_new_y()] != 4)) { //
        if(h->Get_new_x() == h->next->Get_X() && h->Get_new_y() == h->next->Get_Y()) { //При случае движения в обратную сторону двигаться дальше
            if(h->Get_Type_head_course() == 't') {
                h->Set_new_x(h->Get_X() + 1);
                h->Set_new_y(h->Get_Y());
                h->Set_Type_head('d');
            }
            else if(h->Get_Type_head_course() == 'd') {
                h->Set_new_x(h->Get_X() - 1);
                h->Set_new_y(h->Get_Y());
                h->Set_Type_head('t');
            }
            else if(h->Get_Type_head_course() == 'r') {
                h->Set_new_x(h->Get_X());
                h->Set_new_y(h->Get_Y() - 1);
                h->Set_Type_head('l');
            }
            else {
                h->Set_new_x(h->Get_X());
                h->Set_new_y(h->Get_Y() + 1);
                h->Set_Type_head('r');
            }
        }
        else
            return 0;
    }
    return 1;
}

int check_head(Head *h1, Head *h2) {
    if(h1->Get_X() == h2->Get_X() && h1->Get_Y() == h2->Get_Y()) {
        return 0;
    }
    return 1;
}