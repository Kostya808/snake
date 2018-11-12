#include <ncurses.h>
#include <class_field.h>
#include <class_head.h>

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
	if (kbhit() == 1) {
        switch(getch()) {
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

void control_one(Head *h1) {
	noecho(); 
	keypad(stdscr, true); 
	cbreak();
    nodelay(stdscr, TRUE);
	if (kbhit() == 1) {
        switch(getch()) {
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
        }
	}
}

int check_head(Head *h1, Head *h2) {
    if (h1->Get_X() == h2->Get_X() && h1->Get_Y() == h2->Get_Y()) {
        return 0;
    }
    return 1;
}

int mode() {
    int y, x, fl = 0, i = 0, choice = 0;

    initscr();

    getmaxyx(stdscr, y, x);

    keypad(stdscr, true);

    while (fl == 0) {
        clear();
        mvwprintw(stdscr, (y - 8) / 2, (x - 35) / 2, "Choose the number of players\n");
        for (i = 0; i < 2; i++) {
            if (i == choice) {
                if (i == 0) {
                    mvwprintw(stdscr, (y  + 2 * i) / 2, (x - 15) / 2, ">One player");
                } else {
                    mvwprintw(stdscr, (y  + 2 * i) / 2, (x - 15) / 2, ">Two players");
                }
            } else {
                if (i == 0) {
                    mvwprintw(stdscr, (y + 2 * i) / 2, (x - 15) / 2, "One player");
                } else {
                    mvwprintw(stdscr, (y  + 2 * i) / 2, (x - 15) / 2, "Two players");
                }
            }
        }
        switch (getch()) {
            case KEY_UP:
                if (choice > 0) {
                    choice--;
                    break;
                }
            case KEY_DOWN:
                if (choice != 1) {
                    choice++;
                    break;
                }
            case 10:
                fl = 1;
                break;
        }
    }
    endwin();
    return choice;
}