#include <class_field.h>
#include <class_fruit.h>
#include <class_head.h>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>

Fields::Fields(int set_size){ 
	size = set_size;
	initial_field();
}

void Fields::initial_field() {
	snake_matrix = new int* [size];
	
	for (i = 0; i < size; i++) {
		snake_matrix[i] = new int[size];
	}
	
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++) {
			if(i == 0 || i == size - 1 || j == 0 || j == size - 1)
				snake_matrix[i][j] = 5;
		}
}


void Fields::initial_snake_making(Head *h){
	snake_matrix[h->Get_X()][h->Get_Y()] = h->Get_Type_head();
	h->next = create_body(h);
	create(h->next, h);
	create(h->next, h);
}

int Fields::field_update(Fruit *f[], Head *h) {
	int buf_x, buf_y, buf2_x, buf2_y, flag = 0, i;
	Body* bypass = h->next;
	buf_x = h->Get_X();
	buf_y = h->Get_Y();
	if(h->Get_X() != h->Get_new_x() || h->Get_Y() != h->Get_new_y()) {
		snake_matrix[h->Get_new_x()][h->Get_new_y()] = h->Get_Type_head();
		while(bypass != NULL) {
			buf2_x = bypass->Get_X();
			buf2_y = bypass->Get_Y();
			snake_matrix[buf2_x][buf2_y] = 0;
			snake_matrix[buf_x][buf_y] = h->Get_Type_body();
			bypass->Set(buf_x, buf_y);
			bypass = bypass->next;
			buf_x = buf2_x;
			buf_y = buf2_y;
		}
		h->tail->Set(buf2_x, buf2_y);
		buf2_x = 0;
		buf2_x = 0;
		for(i = 0; i < 3; i++) {
			if (f[i]->Get_X() == h->Get_new_x() && f[i]->Get_Y() == h->Get_new_y()) {
				eating_fruit(f[i], h);
				flag = 1;
			}
		}
		h->Set(h->Get_new_x(), h->Get_new_y());
	}
	if (flag == 1)
		return 1;
	return 0;
}

void Fields::eating_fruit(Fruit *f, Head *h) {
	h->Set_score(h->Get_score() + f->Get_score());
	if (f->Get_growth() == 1) {
		create(h->next, h);
	}
	else if (f->Get_growth() == 2) {
		create(h->next, h);
		create(h->next, h);
	}
	f->Set_life(0);
	f->Set(size, size);
}

void Fields::create(Body *&node, Head *h) {
	if(node == NULL) {
		node = create_body(h);
	}
	else {
		create(node->next, h);
	}
}

Body* Fields::create_body(Head *h) {
	int x, y, flag = 0;
	if (h->tail->Get_X() < size -1) {
		if (snake_matrix[h->tail->Get_X() + 1][h->tail->Get_Y()] == 0 && flag == 0) {
			x = h->tail->Get_X() + 1;
			y = h->tail->Get_Y();
			flag = 1;
		}
	}
		if (snake_matrix[h->tail->Get_X() - 1][h->tail->Get_Y()] == 0 && flag == 0) {
		x = h->tail->Get_X() - 1;
		y = h->tail->Get_Y();
		flag = 1;
	}
	if (h->tail->Get_Y() < size - 1) {
		if (snake_matrix[h->tail->Get_X()][h->tail->Get_Y() + 1] == 0 && flag == 0) {
			x = h->tail->Get_X();
			y = h->tail->Get_Y() + 1;
			flag = 1;
		}
	}
		if (snake_matrix[h->tail->Get_X()][h->tail->Get_Y() - 1] == 0 && flag == 0) {
		x = h->tail->Get_X();
		y = h->tail->Get_Y() - 1;
		flag = 1;
	}
	if(flag == 1) {
		Body* body = new Body(x, y);
		h->tail->Set(x, y);
		return body;
	}
	return NULL;
}

void Fields::print(Head * h1, Head * h2) {
	initscr();
	clear();
	int i, j;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			if(snake_matrix[i][j] == h1->Get_Type_head())
				printw("K ");
            else if(snake_matrix[i][j] == h2->Get_Type_head())
                printw("S ");
			else if(snake_matrix[i][j] == h1->Get_Type_body())
                printw("O ");
            else if(snake_matrix[i][j] == h2->Get_Type_body())
                printw("0 ");
            else if(snake_matrix[i][j] == 3)
                printw("A ");
            else if(snake_matrix[i][j] == 4)
                printw("B ");
            else if(snake_matrix[i][j] == 5)
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


void Fields::print(Head * h) {
	initscr();
	clear();
	int i, j;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			if(snake_matrix[i][j] == h->Get_Type_head())
				printw("K ");
			else if(snake_matrix[i][j] == h->Get_Type_body())
                printw("O ");
            else if(snake_matrix[i][j] == 3)
                printw("A ");
            else if(snake_matrix[i][j] == 4)
                printw("B ");
            else if(snake_matrix[i][j] == 5)
                printw("##");
            else
				printw("  ");
		}
		printw("\n");
	}
        printw("Score player 1: %d\n", h->Get_score());
    endwin();
}

int Fields::automotion(Head *h) {
	if(h->Get_Type_head_course() == 't') 
      		h->Set_new_x(h->Get_X() - 1);
	if(h->Get_Type_head_course() == 'd') 
      		h->Set_new_x(h->Get_X() + 1);
	if(h->Get_Type_head_course() == 'r') 
     		h->Set_new_y(h->Get_Y() + 1);
	if(h->Get_Type_head_course() == 'l') 
      		h->Set_new_y(h->Get_Y() - 1);
    if((snake_matrix[h->Get_new_x()][h->Get_new_y()] != 0 && //проверка на возможность хода
        snake_matrix[h->Get_new_x()][h->Get_new_y()] != 3 &&
        snake_matrix[h->Get_new_x()][h->Get_new_y()] != 4)) { //
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

void Fields::add_fruit(Fields * s, Fruit * f) {
	if (f->Get_life() != 1) {
		fruit_making(f);
  	}
	if(f->Get_type() == 'a')
		snake_matrix[f->Get_X()][f->Get_Y()] = 3;
	else
		snake_matrix[f->Get_X()][f->Get_Y()] = 4;
}

void Fields::fruit_making(Fruit *f) {
	int flag = 1, rand_type, check_X, check_Y;
	srand(time(NULL));
	while(flag == 1) {
		check_X = rand() % size;
		check_Y = rand() % size;
		if(snake_matrix[check_X][check_Y] == 0) {
			flag = 0;
			f->Set(check_X, check_Y);
		}
	}
	rand_type = rand() % 10;
	if(rand_type % 2 == 0) {
		f->Set('a');
		f->Set_score(100);
		f->Set_growth(1);
	}
	else {
		f->Set('b');
		f->Set_score(200);
		f->Set_growth(2);
	}
	f->Set_life(1);
}