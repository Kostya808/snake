#include "class_field.h"
#include "class_fruit.h"
#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>

int main() {
	int flag1 = 1, flag2 =1, pause = 170000;
	Fields s;
	Fruit f;
	Head h1(20, 30);
	Head h2(20, 10);
	s.initial_snake_making(&h1);
	s.initial_snake_making(&h2);
	f.fruit_making(&s);
	while(flag1 == 1 && flag2 == 1) {
		print(&s, &h1, &h2);
		f.fruit_print(&s);
		control(&h1, &h2);
		flag1 = automotion(&s, &h1);
		flag2 = automotion(&s, &h2);
		s.field_update(&f, &h1);
		s.field_update(&f, &h2);
		usleep(170000);
		//pause -= 1000;
	}
   endwin();
	return 0;
}