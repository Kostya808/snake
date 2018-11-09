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

int check_head(Head *h1, Head *h2) {
    if(h1->Get_X() == h2->Get_X() && h1->Get_Y() == h2->Get_Y()) {
        return 0;
    }
    return 1;
}